typedef vector<int>::iterator iter;

class WaveletTree {
 public:
  int L, H;
  WaveletTree *l, *r;
  vector<int> frq;

  WaveletTree(iter fr, iter to, int x, int y) {
    L = x, H = y;
    if (fr >= to) return;

    int M = L + ((H - L) >> 1);
    auto F = [M](int x) { return x <= M; };

    frq.reserve(to - fr + 1);
    frq.push_back(0);
    for (auto it = fr; it != to; it++) frq.push_back(frq.back() + F(*it));

    if (H == L) return;
    auto pv = stable_partition(fr, to, F);
    l = new WaveletTree(fr, pv, L, M);
    r = new WaveletTree(pv, to, M + 1, H);
  }

  // Find the k-th smallest element in positions [i,j)
  int quantile(int l, int r, int k) {
    if (l > r) return 0;
    if (L == H) return L;
    int inLeft = frq[r] - frq[l - 1];
    int lb = frq[l - 1], rb = frq[r];
    if (k <= inLeft) return this->l->quantile(lb + 1, rb, k);
    return this->r->quantile(l - lb, r - rb, k - inLeft);
  }

  // Count occurrences of number c until position i -> [0, i].
  int rank(int c, int i) { return until(c, min(i + 1, (int)frq.size() - 1)); }

  int until(int c, int i) {
    if (c > H or c < L) return 0;
    if (L == H) return i;

    int M = L + ((H - L) >> 1);
    int r = frq[i];
    if (c <= M)
      return this->l->until(c, r);
    else
      return this->r->until(c, i - r);
  }

  // Count number of occurrences of numbers in the range [a, b]
  int range(int i, int j, int a, int b) const {
    if (b < a or j < i) return 0;
    return range(i, j + 1, L, H, a, b);
  }

  int range(int i, int j, int a, int b, int L, int U) const {
    if (b < L or U < a) return 0;
    if (L <= a and b <= U) return j - i;
    int M = a + ((b - a) >> 1);
    int ri = frq[i], rj = frq[j];
    return this->l->range(ri, rj, a, M, L, U) +
           this->r->range(i - ri, j - rj, M + 1, b, L, U);
  }

  // Number of elements greater than or equal to k in [l, r];
  // Can count distinct in a range with aux vector of next pos
  int greater(int l, int r, int k) { return _greater(l + 1, r + 1, k); }

  int _greater(int l, int r, int k) {
    if (l > r or k > H) return 0;
    if (L >= k) return r - l + 1;

    int ri = frq[l - 1], rj = frq[r];
    return this->l->_greater(ri + 1, rj, k) +
           this->r->_greater(l - ri, r - rj, k);
  }
};

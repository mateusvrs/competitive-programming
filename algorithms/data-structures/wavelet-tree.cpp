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

  // Find the k-th smallest element in positions [i,j].
  // TO BE IMPLEMENTED
  int quantile(int k, int i, int j) const { return 0; }

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
};
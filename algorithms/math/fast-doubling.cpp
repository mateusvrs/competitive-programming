template <typename T>
class FastDoubling {
 public:
  vector<T> sts;
  T a, b, c, d;
  int mod;

  FastDoubling(int mod = 1e9 + 7) : sts(2), mod(mod) {}

  T fib(T x) {
    fill(all(sts), 0);
    a = 0, b = 0, c = 0, d = 0;
    fast_doubling(x, sts);
    return sts[0];
  }

  void fast_doubling(T n, vector<T>& res) {
    if (n == 0) {
      res[0] = 0;
      res[1] = 1;
      return;
    }
    fast_doubling(n >> 1, res);

    a = res[0];
    b = res[1];
    c = (b << 1) - a;

    if (c < 0) c += mod;

    c = (a * c) % mod;
    d = (a * a + b * b) % mod;
    if (n & 1) {
      res[0] = d;
      res[1] = c + d;
    } else {
      res[0] = c;
      res[1] = d;
    }
  }
};
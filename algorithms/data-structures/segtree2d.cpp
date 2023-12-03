template <typename T, auto op>
class SegTree {
private:
  T e;
  ll n, m;
  vector<vector<T>> seg;

public:
  SegTree(ll n, ll m, T e)
    : e(e), n(n), m(m), seg(2 * n, vector<T>(2 * m, e)) {}

  void assign(ll x, ll y, T v) {
    ll ny = y += m;
    for (x += n; x; x >>= 1, y = ny) {
      if (x >= n) seg[x][y] = v;
      else seg[x][y] = op(seg[2 * x][y], seg[2 * x + 1][y]);

      while (y >>= 1) seg[x][y] = op(seg[x][2 * y], seg[x][2 * y + 1]);
    }
  }

  T query(ll lx, ll rx, ll ly, ll ry) {
    ll ans = e, nx = rx + n, my = ry + m;

    for (lx += n, ly += m; lx <= ly; ++lx >>= 1, --ly >>= 1)
      for (rx = nx, ry = my; rx <= ry; ++rx >>= 1, --ry >>= 1) {
        if (lx & 1 and rx & 1) ans = op(ans, seg[lx][rx]);
        if (lx & 1 and !(ry & 1)) ans = op(ans, seg[lx][ry]);
        if (!(ly & 1) and rx & 1) ans = op(ans, seg[ly][rx]);
        if (!(ly & 1) and !(ry & 1)) ans = op(ans, seg[ly][ry]);
      }

    return ans;
  }
};
using SegT = ll;

struct QueryT {
  SegT mx, mn;
  QueryT() : mx(numeric_limits<SegT>::min()), mn(numeric_limits<SegT>::max()) {}
  QueryT(SegT _v) : mx(_v), mn(_v) {}
};

inline QueryT combine(QueryT ln, QueryT rn, ii lr1, ii lr2) {
  ln.mx = max(ln.mx, rn.mx);
  ln.mn = min(ln.mn, rn.mn);
  return ln;
}

using LazyT = SegT;

inline QueryT applyLazyInQuery(QueryT q, LazyT l, ii lr) {
  if (q.mx == QueryT().mx) q.mx = SegT();
  if (q.mn == QueryT().mn) q.mn = SegT();
  q.mx += l, q.mn += l;
  return q;
}

inline LazyT applyLazyInLazy(LazyT a, LazyT b) { return a + b; }

using UpdateT = SegT;

inline QueryT applyUpdateInQuery(QueryT q, UpdateT u, ii lr) {
  if (q.mx == QueryT().mx) q.mx = SegT();
  if (q.mn == QueryT().mn) q.mn = SegT();
  q.mx += u, q.mn += u;
  return q;
}

inline LazyT applyUpdateInLazy(LazyT l, UpdateT u, ii lr) { return l + u; }

template <typename Qt = QueryT, typename Lt = LazyT, typename Ut = UpdateT,
          auto C = combine, auto ALQ = applyLazyInQuery,
          auto ALL = applyLazyInLazy, auto AUQ = applyUpdateInQuery,
          auto AUL = applyUpdateInLazy>
struct LazySegmentTree {
  int n, h;
  vector<Qt> ts;
  vector<Lt> ds;
  vector<ii> lrs;

  LazySegmentTree(int _n)
    : n(_n),
      h(sizeof(int) * 8 - __builtin_clz(n)),
      ts(n << 1),
      ds(n),
      lrs(n << 1) {
    for (int i = 0; i < n; i++) lrs[i + n] = {i, i};
    for (int i = n - 1; i > 0; i--) {
      lrs[i] = {lrs[i << 1].first, lrs[i << 1 | 1].second};
    }
  }

  LazySegmentTree(const vector<Qt> &xs) : LazySegmentTree(xs.size()) {
    copy(all(xs), ts.begin() + n);
    for (int i = 0; i < n; i++) lrs[i + n] = {i, i};
    for (int i = n - 1; i > 0; i--) {
      ts[i] = C(ts[i << 1], ts[i << 1 | 1], lrs[i << 1], lrs[i << 1 | 1]);
    }
  }

  void set(int p, Qt v) {
    ts[p + n] = v;
    build(p + n);
  }

  void upd(int l, int r, Ut v) {
    l += n, r += n + 1;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    build(l0), build(r0 - 1);
  }

  Qt qry(int l, int r) {
    l += n, r += n + 1;
    push(l), push(r - 1);
    Qt resl = Qt(), resr = Qt();
    ii lr1 = {l, l}, lr2 = {r, r};
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = C(resl, ts[l], lr1, lrs[l]), l++;
      if (r & 1) r--, resr = C(ts[r], resr, lrs[r], lr2);
    }
    return C(resl, resr, lr1, lr2);
  }

  void build(int p) {
    while (p > 1) {
      p >>= 1;
      ts[p] = ALQ(C(ts[p << 1], ts[p << 1 | 1], lrs[p << 1], lrs[p << 1 | 1]),
                  ds[p], lrs[p]);
    }
  }

  void push(int p) {
    for (int s = h; s > 0; s--) {
      int i = p >> s;
      if (ds[i] != Lt()) {
        apply(i << 1, ds[i]), apply(i << 1 | 1, ds[i]);
        ds[i] = Lt();
      }
    }
  }

  inline void apply(int p, Ut v) {
    ts[p] = AUQ(ts[p], v, lrs[p]);
    if (p < n) ds[p] = AUL(ds[p], v, lrs[p]);
  }
};

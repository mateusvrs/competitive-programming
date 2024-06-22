// We consider the rotations
// as distinct (0, 10, 10+9, 10+9+8...)
vi pos = {0, 10, 19, 27, 34, 40, 45, 49, 52, 54, 55};

const int MAXP = 10;

struct Poly {
  ii v[MAXP];
  int64_t id;
  int n;

  Poly() {
    n = 1;
    v[0] = {0, 0};
    normalize();
  }

  Poly(vii &vp) {
    n = vp.size();
    for (int i = 0; i < n; i++) v[i] = vp[i];
    normalize();
  }

  ii &operator[](int i) { return v[i]; }

  bool add(int a, int b) {
    for (int i = 0; i < n; i++) {
      auto [f, s] = v[i];
      if (f == a and s == b) return false;
    }

    v[n++] = ii{a, b};
    normalize();
    return true;
  }

  void normalize() {
    int mx = 100, my = 100;
    for (int i = 0; i < n; i++) {
      auto [f, s] = v[i];
      mx = min(mx, f), my = min(my, s);
    }

    id = 0;
    for (int i = 0; i < n; i++) {
      auto &[f, s] = v[i];
      f -= mx, s -= my;
      id |= (1LL << (pos[f] + s));
    }
  }

  bool operator<(Poly oth) { return id < oth.id; }
};

vector<Poly> poly[MAXP + 1];

void buildPoly(int mxN) {
  for (int i = 0; i <= mxN; i++) poly[i].clear();

  Poly init;
  queue<Poly> q;
  unordered_set<int64_t> used;
  q.push(init);
  used.insert(init.id);
  while (not q.empty()) {
    Poly u = q.front();
    q.pop();
    poly[u.n].emplace_back(u);

    if (u.n == mxN) continue;

    for (int i = 0; i < u.n; i++) {
      for (auto [dx, dy] : dir4) {
        Poly to = u;
        auto [f, s] = to[i];
        bool ok = to.add(f + dx, s + dy);

        if (ok and not used.count(to.id)) {
          q.push(to);
          used.insert(to.id);
        }
      }
    }
  }
}

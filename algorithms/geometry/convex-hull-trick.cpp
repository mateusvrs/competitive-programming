template <typename T = ll> struct ConvexHullTrick {
  static constexpr T inf = numeric_limits<T>::max();

  struct Line {
    T a, b;
    mutable T x_inter;
    T eval(T x) const { return a * x + b; }
    bool operator<(const Line& rhs) const { return a < rhs.a; }
    bool operator<(T x) const { return x_inter < x; }
  };
  multiset<Line, less<>> ln;

  T query(T x) const {
    auto it = ln.lower_bound(x);
    if (it == ln.end()) return inf;
    return it->eval(x);
  }

  void add(T a, T b) {
    auto it = ln.insert({a, b, 0});
    while (overlap(it)) ln.erase(next(it)), update(it);
    if (it != ln.begin() and !overlap(prev(it))) it = prev(it), update(it);
    while (it != ln.begin() and overlap(prev(it))) it = prev(it), ln.erase(next(it)), update(it);
  }
private:
  void update(auto it) const {
    if (next(it) == ln.end()) it->x_inter = inf;
    else if (it->a == next(it)->a) (it->x_inter = it->b >= next(it)->b ? inf : -inf);
    else {
      auto h = (it->b - next(it)->b);
      auto l = (next(it)->a - it->a);
      it->x_inter = h / l - ((h ^ l) < 0 && h % l);
    }
  }

  bool overlap(auto it) const {
    update(it);
    if (next(it) == ln.end()) return false;
    if (it->a == next(it)->a) return it->b >= next(it)->b;
    return it->x_inter >= next(it)->x_inter;
  }
};
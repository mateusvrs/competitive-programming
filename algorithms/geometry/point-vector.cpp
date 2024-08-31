template <typename T>
struct Point {
  T x, y;

  Point(T x = 0, T y = 0) : x(x), y(y) {}

  inline Point operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
  }
  inline Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  inline Point operator+(const T &k) const { return Point(x + k, y + k); }
  inline Point operator-(const T &k) const { return Point(x - k, y - k); }
  inline Point operator*(const T &k) const { return Point(x * k, y * k); }
  inline Point operator/(const T &k) const { return Point(x / k, y / k); }

  inline Point &operator+=(const Point &p) {
    x += p.x, y += p.y;
    return *this;
  }
  inline Point &operator-=(const Point &p) {
    x -= p.x, y -= p.y;
    return *this;
  }
  inline Point &operator+=(const T &k) {
    x += k, y += k;
    return *this;
  }
  inline Point &operator-=(const T &k) {
    x -= k, y -= k;
    return *this;
  }
  inline Point &operator*=(const T &k) {
    x *= k, y *= k;
    return *this;
  }
  inline Point &operator/=(const T &k) {
    x /= k, y /= k;
    return *this;
  }

  inline bool operator==(const Point &p) const {
    return eq(x, p.x) and eq(y, p.y);
  }
  inline bool operator<(const Point &p) const {
    return eq(x, p.x) ? y < p.y : x < p.x;
  }
  inline bool operator>(const Point &p) const {
    return eq(x, p.x) ? y > p.y : x > p.x;
  }
  inline bool operator<=(const Point &p) const {
    return *this == p or *this < p;
  }
  inline bool operator>=(const Point &p) const {
    return *this == p or *this > p;
  }

  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << p.x << ' ' << p.y;
  }
  friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }

  template <typename U>
  void rotate(U rad) {
    tie(x, y) =
      make_pair(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  template <typename U>
  Point<U> rotated(U rad) const {
    return Point<U>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  inline T dot(const Point &p) const { return x * p.x + y * p.y; }
  inline T cross(const Point &p) const { return x * p.y - y * p.x; }
  inline T cross(const Point &a, const Point &b) const {
    return (a - *this).cross(b - *this);
  }
  inline T dist2() const { return x * x + y * y; }
  inline double dist() const { return hypot(x, y); }
  inline double angle() const { return atan2(y, x); }
  inline double norm() const { return sqrt(dot(*this)); }
  inline Point rot90() const { return Point(-y, x); }
  inline Point to(const Point &p) const { return p - *this; }
};

template <typename T>
struct Vector {
  T x = 0, y = 0;

  Vector(const Point<T> &A, const Point<T> &B) : x(B.x - A.x), y(B.y - A.y) {}

  T length() const { return hypot(x, y); }
};

template <typename T>
struct Line {
  T a, b, c;

  Line(T av, T bv, T cv) : a(av), b(bv), c(cv) {}

  Line(const Point<T> &P, const Point<T> &Q)
    : a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y) {}
};
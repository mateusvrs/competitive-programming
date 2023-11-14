ll fast_exp_it(ll a, ll n, ll mod = LLONG_MAX) {
  a %= mod;
  ll res = 1;

  while (n) {
    if (n & 1) (res *= a) %= mod;

    (a *= a) %= mod;
    n >>= 1;
  }

  return res;
}
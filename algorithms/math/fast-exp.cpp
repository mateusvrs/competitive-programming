ll fast_exp(ll a, ll n, ll mod = LLONG_MAX) {
  if (n == 0) return 1;
  if (n == 1) return a;

  ll x = fast_exp(a, n / 2, mod) % mod;

  return ((x * x) % mod * (n & 1 ? a : 1ll)) % mod;
}
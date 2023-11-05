long long fast_exp(long long a, int n) {
  if (n == 1) return a;

  auto x = fast_exp(a, n / 2);

  return x * x * (n % 2 ? a : 1);
}
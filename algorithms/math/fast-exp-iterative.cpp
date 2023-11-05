long long fast_exp_it(long long a, int n) {
  long long res = 1, base = a;

  while (n) {
    if (n & 1) res *= base;

    base *= base;
    n >>= 1;
  }

  return res;
}
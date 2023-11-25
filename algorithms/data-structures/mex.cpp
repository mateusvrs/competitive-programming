ll mex(vl const& A) {
  static bool used[MAX + 1ll] = {0};

  for (ll x : A) {
    if (x <= MAX) used[x] = true;
  }

  ll result = 0;
  while (used[result]) ++result;

  for (ll x : A) {
    if (x <= MAX) used[x] = false;
  }

  return result;
}
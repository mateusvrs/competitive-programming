ostream& operator<<(ostream& dest, __int128_t value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char* d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) dest.setstate(ios_base::badbit);
  }
  return dest;
}

istream& operator>>(istream& is, __int128_t& value) {
  string s;
  is >> s;

  __int128_t res = 0;
  size_t i = 0;

  bool neg = false;
  if (s[i] == '-') neg = 1, i++;
  for (; i < s.size(); ++i) (res *= 10) += (s[i] - '0');

  value = neg ? -res : res;
  return is;
}
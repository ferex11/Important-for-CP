long long ncr(long long n, long long r) {
  if (r > n) {
    return 0;
  }
  r = min(r, n - r);
  long long res = 1;
  for (long long i = 1; i <= r; i++) {
    res = res * (n - r + i) / i;
  }
  return res;
}

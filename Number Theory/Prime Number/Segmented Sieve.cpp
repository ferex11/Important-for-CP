vector<int> sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}
vector<ll> segemeted_sieve(ll L, ll R) {
  if (L > R || R < 2) {
    return {};
  }
  ll limit = sqrtl(R);
  while ((limit + 1) * (limit + 1) <= R) {
    limit++;
  }
  while (limit * limit > R) {
    limit--;
  }
  vector<int> primes = sieve((int)limit);
  vector<bool> is_prime(R - L + 1, true);
  for (ll p : primes) {
    ll start = L + (p - L % p) % p;
    start = max(start, p * p);
    for (ll j = start; j <= R; j += p) {
      is_prime[j - L] = false;
    }
  }
  vector<ll> ans;
  for (ll i = L; i <= R; i++) {
    if (is_prime[i - L]) {
      ans.push_back(i);
    }
  }
  return ans;
}
// Time Complexity:  O(√R log(log R) + (R-L+1) log(log R))
// Space Complexity: O(√R + R-L+1)

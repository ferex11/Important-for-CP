ll gcd(ll a, ll b) {
  while (b != 0) {
    ll r = a % b;
    a = b;
    b = r;
  }
  return a;
}
ll lcm(ll a, ll b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  return (a / gcd(a, b)) * b;
}
// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)

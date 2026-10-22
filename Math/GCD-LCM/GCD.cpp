ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// Time Complexity: O(log(min(a,b)))
// Space Complexity: O(1)

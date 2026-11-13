#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define sp ' '
const ll INF = 4e18;
const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> dist(n + 1, vector<ll> (n + 1, INF));
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    dist[u][v] = min(dist[u][v], w);
  }
  for (int via = 1; via <= n; via++) {
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        if (dist[u][via] == INF || dist[via][v] == INF) {
          continue;
        }
        dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    if (dist[u][u] < 0) {
      cout << "Negative Cycle Exists" << endl;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

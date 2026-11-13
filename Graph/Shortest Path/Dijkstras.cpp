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
  vector<vector<pair<int, ll>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int src;
  cin >> src;
  vector<ll> dist(n + 1, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] > d) {
      continue;
    }
    for (auto [v, w] : adj[u]) {
      if (d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({dist[v], v});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (dist[i] == INF ? -1 : dist[i]) << sp;
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

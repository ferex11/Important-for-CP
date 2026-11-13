#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define sp ' '
const ll INF = 4e18;
const int MOD = 1e9 + 7;

struct Edge {
  int u, v;
  ll w;
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }
  int s;
  cin >> s;
  vector<ll> dist(n + 1, INF);
  dist[s] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (auto [u, v, w] : edges) {
      if (dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }
  for (auto [u, v, w] : edges) {
    if (dist[u] != INF && dist[u] + w < dist[v]) {
      cout << "Negative cycle" << endl;
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

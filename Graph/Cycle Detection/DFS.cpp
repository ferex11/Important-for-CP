#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define inf 1e18
#define MOD 1e9 + 7

vector<vector<int>> adj;
vector<bool> vis;

bool dfs(int u, int p) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    if (vis[v]) {
      return true;
    }
    if (dfs(v, u)) {
      return true;
    }
  }
  return false;
}
void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  vis.assign(n + 1, false);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool has_cycle = false;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfs(i, -1)) {
        has_cycle = true;
        break;
      }
    }
  }
  cout << (has_cycle ? "Yes" : "No") << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

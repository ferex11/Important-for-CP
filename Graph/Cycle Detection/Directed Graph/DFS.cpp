#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define inf 1e18
#define MOD 1e9 + 7

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> path_vis;

bool dfs(int u) {
  vis[u] = true;
  path_vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      if (dfs(v)) {
        return true;
      }
    } else if (path_vis[v]) {
      return true;
    }
  }
  path_vis[u] = false;
  return false;
}
void solve() {
  int n, m;
  cin >> n >> m;
  adj.assign(n, {});
  vis.assign(n, false);
  path_vis.assign(n, false);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int u = 0; u < n; u++) {
    if (!vis[u]) {
      if (dfs(u)) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

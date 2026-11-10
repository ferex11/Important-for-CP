#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define inf 1e18
#define MOD 1e9 + 7

vector<vector<int>> adj, rev_adj;
vector<bool> vis;
vector<int> order;

void dfs1(int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs1(v);
    }
  }
  order.push_back(u);
}
void dfs2(int u, vector<int>& components) {
  vis[u] = true;
  components.push_back(u);
  for (int v : rev_adj[u]) {
    if (!vis[v]) {
      dfs2(v, components);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  rev_adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    rev_adj[v].push_back(u);
  }
  vis.assign(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs1(i);
      
    }
  }
  vis.assign(n + 1, false);
  int scc_count = 0;
  for (int u : order) {
    if (!vis[u]) {
      vector<int> components;
      dfs2(u, components);
      scc_count++;
      cout << "SCC " << scc_count << ": ";
      for (int x : components) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
  cout << "Total SCCs: " << scc_count << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

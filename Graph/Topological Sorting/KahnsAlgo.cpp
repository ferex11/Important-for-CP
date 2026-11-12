#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define inf 1e18
#define MOD 1e9 + 7

vector<vector<int>> adj;

void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indegree[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> topo;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (int v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }
  if ((int) topo.size() != n) {
    cout << "Cycle detected!" << endl;
  } else {
    for (int x : topo) {
      cout << x << " ";
    }
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

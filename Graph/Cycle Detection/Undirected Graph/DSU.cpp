#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define inf 1e18
#define MOD 1e9 + 7

vector<vector<int>> adj;
vector<bool> vis;

class DSU {
private:
  vector<int> parent;
  vector<int> sz;
public:
  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n, 1);
  }
  int find(int u) {
    if (u == parent[u]) {
      return u;
    }
    return parent[u] = find(parent[u]);
  }
  void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return;
    }
    if (sz[u] < sz[v]) {
      swap(u, v);
    }
    parent[v] = u;
    sz[u] += sz[v];
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (dsu.find(u) == dsu.find(v)) {
      cout << "Yes" << endl;
      return;
    }
    dsu.union_sets(u, v);
  }
  cout << "No" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

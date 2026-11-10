#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define inf 1e18
#define MOD 1e9 + 7

vector<vector<int>> adj;
vector<int> tin;
vector<int> low;
vector<bool> in_stack;
stack<int> st;
vector<vector<int>> components;
int timer = 0;
int scc_count = 0;

void tarjan(int u) {
  tin[u] = low[u] = timer++;
  st.push(u);
  in_stack[u] = true;
  for (int v : adj[u]) {
    if (tin[v] == -1) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], tin[v]);
    }
  }
  if (low[u] == tin[u]) {
    vector<int> component;
    cout << "SCC " << scc_count << ": ";
    while (true) {
      int v = st.top();
      st.pop();
      in_stack[v] = false;
      component.push_back(v);
      if (u == v) {
        break;
      }
    }
    components.push_back(component);
    scc_count++;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  adj.assign(n + 1, {});
  tin.assign(n + 1, -1);
  low.assign(n + 1, -1);
  in_stack.assign(n + 1, false);
  while (!st.empty()) {
    st.pop();
  }
  components.clear();
  timer = 0;
  scc_count = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (tin[i] == -1) {
      tarjan(i);
    }
  }
  for (int i = 0; i < scc_count; i++) {
    cout << "SCC " << i + 1 << ": ";
    for (int v : components[i]) {
      cout << v << " " ;
    }
    cout << endl;
  }
  cout << "Total SCCs: " << scc_count << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

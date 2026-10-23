struct SparseTable {
  int n, LOG;
  vector<int> lg;
  vector<vector<ll>> st;
  SparseTable(const vector<ll>& a) {
    n = (int)a.size();
    LOG = 1;
    while ((1 << LOG) <= n) {
      LOG++;
    }
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      lg[i] = lg[i / 2] + 1;
    }
    st.assign(LOG, vector<ll>(n));
    for (int i = 0; i < n; i++) {
      st[0][i] = a[i];
    }
    for (int k = 1; k < LOG; k++) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
      }
    }
  }
  ll query(int l, int r) {
    int k = lg[r - l + 1];
    return min(st[k][l], st[k][r - (1 << k) + 1]
    );
  }
};

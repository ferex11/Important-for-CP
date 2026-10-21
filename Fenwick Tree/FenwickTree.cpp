struct Fenwick {
  int n;
  vector<ll> bit;
  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }
  void update(int i, int delta) {
    while (i <= n) {
      bit[i] += delta;
      i += i & -i;
    }
  }
  ll query(int i) {
    ll sum = 0;
    while (i > 0) {
      sum += bit[i];
      i -= i & -1;
    }
    return sum;
  }
  ll rangeQuery(int l, int r) {
    return query(r) - query(l - 1);
  }
};

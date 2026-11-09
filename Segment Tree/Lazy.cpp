class SegmentTree {
private:
  int n;
  vector<int> tree;
  vector<int> lazy;
  vector<int> arr;
  void build(int ind, int low, int high) {
    if (low == high) {
      tree[ind] = arr[low];
      return;
    }
    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
  }
  void update(int ind, int low, int high, int l, int r, int val) {
    if (lazy[ind] != 0) {
      tree[ind] += (high - low + 1) * lazy[ind];
      if (low != high) {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }
      lazy[ind] = 0;
    }
    if (high < l || r < low) return;
    if (l <= low && high <= r) {
      tree[ind] += (high - low + 1) * val;
      if (low != high) {
        lazy[2 * ind + 1] += val;
        lazy[2 * ind + 2] += val;
      }
      return;
    }
    int mid = (low + high) >> 1;
    update(2 * ind + 1, low, mid, l, r, val);
    update(2 * ind + 2, mid + 1, high, l, r, val);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
  }
  int query(int ind, int low, int high, int l, int r) {
    if (lazy[ind] != 0) {
      tree[ind] += (high - low + 1) * lazy[ind];
      if (low != high) {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }
      lazy[ind] = 0;
    }
    if (high < l || r < low) return 0;
		if (l <= low && high <= r) return tree[ind];
		int mid = (low + high) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
  }
public:
  SegmentTree(vector<int>& input) {
    arr = input;
    n = arr.size();
    tree.resize(4 * n);
    lazy.resize(4 * n);
    build(0, 0, n - 1);
  }
  void setValues(int l, int r, int val) {
    update(0, 0, n - 1, l, r, val);
  }
  int getSum(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

class SegmentTree {
private:
	vector<ll> tree;
	vector<ll> arr;
	int n;
	void build(int ind, int low, int high) {
		if (low == high) {
			tree[ind] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid);
		build(2 * ind + 2, mid + 1, high);
		tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
	}
	ll query(int ind, int low, int high, int l, int r) {
		if (l > high || r < low)
			return 0;
		if (l <= low && high <= r)
			return tree[ind];
		int mid = (low + high) / 2;
		ll leftRes = query(2 * ind + 1, low, mid, l, r);
		ll rightRes = query(2 * ind + 2, mid + 1, high, l, r);
		return leftRes + rightRes;
	}
	void update(int ind, int low, int high, int pos, int val) {
		if (low == high) {
			tree[ind] = val;
			return;
		}
		int mid = (low + high) / 2;
		if (pos <= mid) {
			update(2 * ind + 1, low, mid, pos, val);
		} else {
			update(2 * ind + 2, mid + 1, high, pos, val);
		}
		tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
	}
public:
	SegmentTree(vector<ll> &input) {
		arr = input;
		n = arr.size();
		tree.resize(4 * n);
		build(0, 0, n - 1);
	}
	ll rangeQuery(int low, int high) {
		return query(0, 0, n - 1, low, high);
	}
	void setValue(int pos, ll val) {
		update(0, 0, n - 1, pos, val);
	}
};

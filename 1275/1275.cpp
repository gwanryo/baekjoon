#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long init(long long *a, vector<long long> &tree, long long node, long long start, long long end) {
	if (start == end) {
		tree[node] = a[start];
		return tree[node];
	}
	else {
		tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		return tree[node];
	}
}

void update(vector<long long> &tree, long long node, long long start, long long end, long long index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
	if (left > end || right < start) {
		return 0;
	}

	if (left <= start && right >= end) {
		return tree[node];
	}

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	long long n, m;
	cin >> n >> m;

	long long i, j;
	long long *a = new long long[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long size = 1 << ((long long)ceil(log2(n)) + 1);
	vector<long long> tree(size);
	init(a, tree, 1, 0, n - 1);

	for (i = 0; i < m; i++) {
		long long x, y, z, w;
		cin >> x >> y >> z >> w;

		if (x > y) swap(x, y);
		if (x >= 1 && x <= n && y >= 1 && y <= n)
			cout << sum(tree, 1, 0, n - 1, x - 1, y - 1) << "\n";
		if (z < 1 || z > n) continue;
		long long diff = w - a[--z];
		a[z] = w;
		update(tree, 1, 0, n - 1, z, diff);
	}

	return 0;
}
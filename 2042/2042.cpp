#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, long long node, long long start, long long end) {
	if (start == end) {
		tree[node] = a[start];
		return tree[node];
	} else {
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
	long long n;
	int m, k;
	cin >> n >> m >> k;

	long long i, j;
	vector<long long> a(n);
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int size = 1 << ((int)ceil(log2(n)) + 1);
	vector<long long> tree(size);
	init(a, tree, 1, 0, n - 1);

	for (i = 0; i < m + k; i++) {
		int x;
		long long y, z;
		cin >> x >> y >> z;

		if (x == 1) {
			long long diff = z - a[--y];
			a[y] = z;
			update(tree, 1, 0, n - 1, y, diff);
		} else if (x == 2) {
			cout << sum(tree, 1, 0, n - 1, y - 1, z - 1) << endl;
		}
	}

	return 0;
}
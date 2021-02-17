#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define candy 1000000
int node;
bool flag = true;

long get(vector<long> &tree, int index, int start, int end, int rank) {
	if (start == end) {
		cout << start << "\n";
		flag = false;
		return start;
	}

	if (flag) {
		if (index * 2 <= node && tree[index * 2] >= rank) {
			return get(tree, index * 2, start, (start + end) / 2, rank);
		}

		rank -= tree[index * 2];

		if (index * 2 + 1 <= node && tree[index * 2 + 1] >= rank) {
			return get(tree, index * 2 + 1, (start + end) / 2 + 1, end, rank);
		}
	}
}

void update(vector<long> &tree, int index, int start, int end, int cdy, long num) {
	if (cdy < start || end < cdy) return;
	tree[index] += num;
	if (start != end) {
		update(tree, index * 2, start, (start + end) / 2, cdy, num);
		update(tree, index * 2 + 1, (start + end) / 2 + 1, end, cdy, num);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
	int n;
	cin >> n;

	int a, b;
	long c;

	node = (int)ceil(log2(candy)) + 1;
	node = 1 << node;
	vector<long> tree(node, 0);

	for (int i = 0; i < n; i++) {
		cin >> a;

		if (a == 1) {
			cin >> b;
			flag = true;
			int idx = get(tree, 1, 0, candy - 1, b);
			update(tree, 1, 0, candy - 1, idx, -1);
		}
		else if (a == 2) {
			cin >> b >> c;
			update(tree, 1, 0, candy - 1, b, c);
		}
	}

	return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define max_depth 21
int parent[max_depth][100001];

void bfs(vector<vector<int>> tree, int *depth, int *visit, int index) {
	queue<int> q;
	q.push(index);
	visit[index] = 1;

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (int i = 0; i < tree[t].size(); i++) {
			if (visit[tree[t][i]] == 0) {
				visit[tree[t][i]] = 1;
				depth[tree[t][i]] = depth[t] + 1;
				parent[depth[index]][tree[t][i]] = t;
				q.push(tree[t][i]);
			}
		}
	}
}

int lca(int *depth, int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);

	for (int i = max_depth - 1; i >= 0; i--) {
		if (depth[x] - depth[y] >= (1 << i))
			x = parent[i][x];
	}

	if (x == y) return x;

	for (int i = max_depth - 1; i >= 0; i--) {
		if (parent[i][x] != parent[i][y]) {
			x = parent[i][x];
			y = parent[i][y];
		}
	}

	return parent[0][x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	int i, j, x, y;
	vector<vector<int>> tree(n + 1);
	int *depth = new int[n + 1];
	int *visit = new int[n + 1];

	for (i = 1; i < n; i++) {
		cin >> x >> y;
		if (x > y) swap(x, y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	for (i = 1; i < n + 1; i++) {
		visit[i] = 0, depth[i] = 0;
		sort(tree[i].begin(), tree[i].end());
	}

	bfs(tree, depth, visit, 1);

	for (i = 1; i < max_depth; i++) {
		for (j = 1; j < n + 1; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> x >> y;
		cout << lca(depth, x, y) << "\n";
	}

	return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>	
using namespace std;

#define max_depth 21
#define inf 2100000000

int parent[max_depth][100001];
int pmax[max_depth][100001];
int pmin[max_depth][100001];

void bfs(vector<vector<pair<int, int>>> tree, int *depth, int *visit, int index) {
	queue<int> q;
	q.push(index);
	visit[index] = 1;

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (int i = 0; i < tree[t].size(); i++) {
			if (visit[tree[t][i].first] == 0) {
				visit[tree[t][i].first] = 1;
				depth[tree[t][i].first] = depth[t] + 1;

				parent[depth[index]][tree[t][i].first] = t;
				pmax[depth[index]][tree[t][i].first] = tree[t][i].second;
				pmin[depth[index]][tree[t][i].first] = tree[t][i].second;

				q.push(tree[t][i].first);
			}
		}
	}
}

pair<int, int> lca(int *depth, int x, int y) {
	int mmax = -inf, mmin = inf;

	if (depth[x] < depth[y]) swap(x, y);

	for (int i = max_depth - 1; i >= 0; i--) {
		if (depth[x] - depth[y] >= (1 << i)) {
			mmax = max(mmax, pmax[i][x]);
			mmin = min(mmin, pmin[i][x]);
			x = parent[i][x];
		}
	}

	if (x == y) return{ mmax, mmin };

	for (int i = max_depth - 1; i >= 0; i--) {
		if (parent[i][x] != parent[i][y]) {
			mmax = max(mmax, max(pmax[i][x], pmax[i][y]));
			mmin = min(mmin, min(pmin[i][x], pmin[i][y]));
			x = parent[i][x];
			y = parent[i][y];
		}
	}

	mmax = max(mmax, max(pmax[0][x], pmax[0][y]));
	mmin = min(mmin, min(pmin[0][x], pmin[0][y]));

	return{ mmax, mmin };
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	int i, j, x, y, z;
	vector<vector<pair<int, int>>> tree(n + 1);
	int *depth = new int[n + 1];
	int *visit = new int[n + 1];

	for (i = 1; i < n; i++) {
		cin >> x >> y >> z;
		if (x > y) swap(x, y);
		tree[x].push_back(make_pair(y, z));
		tree[y].push_back(make_pair(x, z));
	}

	for (i = 1; i < n + 1; i++) {
		visit[i] = 0, depth[i] = 0;
		sort(tree[i].begin(), tree[i].end());
	}

	bfs(tree, depth, visit, 1);

	for (i = 1; i < max_depth; i++) {
		for (j = 1; j < n + 1; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			pmax[i][j] = max(pmax[i - 1][j], pmax[i - 1][parent[i - 1][j]]);
			pmin[i][j] = min(pmin[i - 1][j], pmin[i - 1][parent[i - 1][j]]);
		}
	}

	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> x >> y;
		pair<int, int> p = lca(depth, x, y);
		cout << p.second << " " << p.first << "\n";
	}

	return 0;
}
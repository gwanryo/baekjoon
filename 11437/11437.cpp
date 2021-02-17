#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<int> tree[], int *parent, int *depth, int *visit, int index) {
	queue<int> q;
	q.push(index);
	visit[index] = 1;
	
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		
		for(int i = 0; i < tree[t].size(); i++) {
			if (visit[tree[t][i]] == 0) {
				visit[tree[t][i]] = 1;
				depth[tree[t][i]] = depth[t] + 1;
				parent[tree[t][i]] = t;
				q.push(tree[t][i]);
			}
		}
	}
}

int lca(int *parent, int *depth, int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	
	while (depth[x] != depth[y]) {
		x = parent[x];
	}
	
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n;
	
	int i, j, x, y;
	vector<int> tree[n + 1];
	int *parent = new int[n + 1];
	int *depth = new int[n + 1];
	int *visit = new int[n + 1];
	
	for(i = 1; i < n; i++) {
		cin >> x >> y;
		if (x > y) swap(x, y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	for(i = 1; i < n + 1; i++) {
		visit[i] = 0, parent[i] = i, depth[i] = 0;
		sort(tree[i].begin(), tree[i].end());
	}
	
	bfs(tree, parent, depth, visit, 1);
	
	cin >> m;
	
	for(i = 0; i < m; i++) {
		cin >> x >> y;
		cout << lca(parent, depth, x, y) << "\n";
	}
	
	return 0;
}
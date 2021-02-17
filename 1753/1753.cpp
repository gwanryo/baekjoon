#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define inf 800001

void dijkstra(vector<vector<pair<int, long long>>> &map, long long *cost, int x) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int ctarget = pq.top().second;
		long long ctarget_cost = -pq.top().first;
		long long pmin = inf;

		pq.pop();

		if (cost[ctarget] < ctarget_cost) continue;

		for (int i = 0; i < map[ctarget].size(); i++) {
			int target = map[ctarget][i].first;
			int target_cost = map[ctarget][i].second;

			if (cost[target] > ctarget_cost + target_cost) {
				cost[target] = ctarget_cost + target_cost;
				pq.push(make_pair(-cost[target], target));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int i, j, x, y, z;
	vector<vector<pair<int, long long>>> map(n + 1);
	long long *cost = new long long[n + 1];

	for (i = 1; i < n + 1; i++) {
		cost[i] = inf;
	}

	for (i = 0; i < m; i++) {
		cin >> x >> y >> z;
		map[x].push_back(make_pair(y, z));
	}
	
	cost[k] = 0;
	dijkstra(map, cost, k);
	
	for(i = 1; i < n + 1; i++) {
		if (cost[i] >= inf) {
			cout << "INF";
		} else {
			cout << cost[i];
		}
		cout << "\n";
	}

	return 0;
}

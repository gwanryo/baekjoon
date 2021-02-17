#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define inf 100000001

bool bellman(vector<vector<pair<int, long long>>> &map, long long *cost, int x) {
	for (int i = 1; i < map.size(); i++) {
		for (int j = 1; j < map.size(); j++) {
			for (int k = 0; k < map[j].size(); k++) {
				int target = map[j][k].first;
				int target_cost = map[j][k].second;

				if (cost[j] != inf && cost[target] > cost[j] + target_cost) {
					cost[target] = cost[j] + target_cost;
					if (i == map.size() - 1) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

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

	cost[1] = 0;

	if (bellman(map, cost, 1)) {
		for (i = 2; i < n + 1; i++) {
			if (cost[i] < inf) {
				cout << cost[i] << "\n";
			} else {
				cout << "-1\n";
			}
			
		}
	} else {
		cout << "-1\n";
	}

	return 0;
}

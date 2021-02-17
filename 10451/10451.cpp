#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int cnt = 0;

void dfs(bool **map, bool *visit, int m, int start) {
	if (visit[start]) {
		cnt++;
		return;
	} else {
		visit[start] = true;
	}

	for (int i = 0; i < m; i++) {
		if (map[start][i]) {
			map[start][i] = false;
			dfs(map, visit, m, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, i, j, k, node, sum = 0;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> m;

		bool **map = new bool*[m];
		bool *visit = new bool[m];
		for (j = 0; j < m; j++) {
			map[j] = new bool[m];
			visit[j] = false;

			for (k = 0; k < m; k++) {
				map[j][k] = false;
			}
		}

		for (j = 0; j < m; j++) {
			cin >> node;
			map[j][node - 1] = true;
		}

		for (j = 0; j < m; j++) {
			dfs(map, visit, m, j);

			for (k = 0; k < m; k++) {
				visit[k] = false;
			}

			sum += cnt;
			cnt = 0;
		}

		for (j = 0; j < m; j++) {
			delete map[j];
		}

		delete[] map, visit;

		cout << sum << "\n";
		sum = 0;
	}

	return 0;
}
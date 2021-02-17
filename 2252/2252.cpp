#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, i, j, x, y;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);
	int *g = new int[n + 1];
	for (i = 1; i < n + 1; i++) g[i] = 0;

	for (i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		g[y]++;
	}

	int cnt = 0;
	i = 0;
	
	while(cnt != n) {
		i++;
		
		if (g[i] == 0) {
			for (j = 0; j < v[i].size(); j++) {
				g[v[i][j]]--;
			}

			cout << i << "\n";
			g[i]--, cnt++, i = 0;
		}
	}

	return 0;
}
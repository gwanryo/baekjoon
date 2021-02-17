#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int map[1000][1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n, m, i, j;
	cin >> n >> m;

	int maxx = 0;
	for (i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (j = 0; j < m; j++) {
			map[i][j] = t[j] - '0';
			if (map[i][j] == 1) maxx = 1;
		}
	}

	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			if (map[i][j] == 0) continue;
			map[i][j] = min(map[i - 1][j - 1],
				min (map[i][j - 1], map[i - 1][j])) + 1;

			if (map[i][j] > maxx) maxx = map[i][j];
		}
	}

	cout << maxx * maxx;

	return 0;
}
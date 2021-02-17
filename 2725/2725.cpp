#include <iostream>
#include <vector>
using namespace std;
#define max 1001

int gcd(int x, int y) {
	while (y) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int **map = new int*[max];
	int i, j, k, n;
	cin >> n;

	for (i = 0; i < max; i++) map[i] = new int[max];

	for (i = 2; i < max; i++) {
		for (j = i; j < max; j++) {
			int g = gcd(i, j);
			map[i][j] = g, map[j][i] = g;
		}
	}

	for (i = 0; i < n; i++) {
		int m;
		cin >> m;

		int cnt = 0;
		for (j = m; j >= 2; j--) {
			for (k = 2; k <= m; k++) {
				if (map[j][k] == 1) cnt++;
			}
		}

		cout << 3 + 2 * (m - 1) + cnt << "\n";
	}

	return 0;
}
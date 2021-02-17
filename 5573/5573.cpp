#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
vector<int> num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	long h, w, n;
	cin >> h >> w >> n;

	int i, j;
	bool **m = new bool*[h];
	long **c = new long*[h + 1];

	for (i = 0; i < h; i++) {
		m[i] = new bool[w];

		for (j = 0; j < w; j++) {
			cin >> m[i][j];
		}
	}

	for (i = 0; i <= h; i++) {
		c[i] = new long[w + 1];
		for (j = 0; j <= w; j++) {
			c[i][j] = 0;
		}
	}

	n--;
	c[0][0] = n;

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (m[i][j]) {
				// Right @ 1
				if (c[i][j] % 2) {
					// Reverse
					c[i][j + 1] += c[i][j] / 2 + 1;
					c[i + 1][j] += c[i][j] / 2;
					m[i][j] = 0;
				} else {
					// Keep
					c[i][j + 1] += c[i][j] / 2;
					c[i + 1][j] += c[i][j] / 2;
				}
			} else {
				// Down @ 1
				if (c[i][j] % 2) {
					// Reverse 
					c[i][j + 1] += c[i][j] / 2;
					c[i + 1][j] += c[i][j] / 2 + 1;
					m[i][j] = 1;
				} else {
					// Keep
					c[i][j + 1] += c[i][j] / 2;
					c[i + 1][j] += c[i][j] / 2;
				}
			}
		}
	}

	int x = 0, y = 0;
	while (x < h && y < w) {
		if (m[x][y]) {
			m[x][y] = 0;
			y++;
		} else {
			m[x][y] = 1;
			x++;
		}
	}

	cout << x + 1 << " " << y + 1;

	return 0;
}
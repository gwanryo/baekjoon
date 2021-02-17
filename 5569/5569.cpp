#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
vector<int> num;
long long f[21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int w, h, i, j;
	cin >> w >> h;

	int map[101][101][2][2];
	// 0 0 => Go right 1 time
	// 0 1 => Go right 2 times
	// 1 0 => Go up 1 time
	// 1 1 => Go up 2 times

	for (i = 0; i < 101; i++) {
		for (j = 0; j < 101; j++) {
			map[i][j][0][0] = 0;
			map[i][j][0][1] = 0;
			map[i][j][1][0] = 0;
			map[i][j][1][1] = 0;
		}
	}

	for (i = 2; i < 101; i++) {
		map[i][1][0][0] = 1;
		map[1][i][1][0] = 1;
	}

	for (i = 2; i <= w; i++) {
		for (j = 2; j <= h; j++) {
			map[i][j][0][0] = (map[i - 1][j][0][0] + map[i - 1][j][0][1]) % 100000;
			map[i][j][0][1] = map[i - 1][j][1][0];
			map[i][j][1][0] = (map[i][j - 1][1][0] + map[i][j - 1][1][1]) % 100000;
			map[i][j][1][1] = map[i][j - 1][0][0];
		}
	}

	cout << (map[w][h][0][0] + map[w][h][0][1] + map[w][h][1][0] + map[w][h][1][1]) % 100000;

	return 0;
}
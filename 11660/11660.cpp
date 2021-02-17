#include <iostream>
#include <vector>
#include <string>
using namespace std;
int number[1024][1024];
int sum[1024][1024];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			number[i][j] = t;
			if (j == 0) sum[i][j] = t;
			else sum[i][j] = sum[i][j - 1] + t;
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;

		int square_sum = 0;
		for (int j = x1; j <= x2; j++) {
			if (y1 == 0) square_sum += sum[j][y2];
			else square_sum += sum[j][y2] - sum[j][y1 - 1];
		}
		cout << square_sum << "\n";
	}

	return 0;
}
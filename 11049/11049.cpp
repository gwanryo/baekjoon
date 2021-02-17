#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, j, k, l;
	int r[501][2] = { { 0, 0 }, }, dp[501][501] = { 0, };

	cin >> n;
	for (i = 0; i < 501; i++) {
		for (j = 0; j < 501; j++) {
			dp[i][j] = 0;
		}
	}

	for (i = 1; i <= n; i++) {
		cin >> r[i][0] >> r[i][1];
		dp[i][i] = 0;
	}

	for (l = 1; l <= n; l++) {
		for (i = 1; i <= n - l; i++) {
			int j = i + l;
			for (k = i; k < j; k++) {
				int c = dp[i][k] + dp[k + 1][j] + (r[i][0] * r[k][1] * r[j][1]);
				if (dp[i][j] == 0 || dp[i][j] > c) dp[i][j] = c;
			}
		}
	}

	cout << dp[1][n] << endl;
	return 0;
}

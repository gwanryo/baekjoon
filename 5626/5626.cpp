#include <iostream>
using namespace std;
typedef long long lld;

int n;
int dt[10001];
lld dp[2][5005];

int main() {
	cin >> n;

	int i, j;
	for (i = 1; i <= n; i++) {
		cin >> dt[i];
	}

	if (dt[1] == -1 || dt[1] == 0) {
		dp[1][0] = 1;
	}

	for (i = 2; i <= n; i++) {
		if (dt[i] != -1) {
			for (j = 0; j <= n / 2 + 1; j++) {
				dp[i & 1][j] = 0;
			}

			if (dt[i]) {
				dp[i & 1][dt[i]] = (dp[(i - 1) & 1][dt[i]] + dp[(i - 1) & 1][dt[i] - 1] + dp[(i - 1) & 1][dt[i] + 1]) % 1000000007;
			} else {
				dp[i & 1][0] = (dp[(i - 1) & 1][1] + dp[(i - 1) & 1][0]) % 1000000007;
			}
			continue;
		}

		dp[i & 1][0] = (dp[(i - 1) & 1][1] + dp[(i - 1) & 1][0]) % 1000000007;
		
		for (j = 1; j <= n / 2 + 1; j++) {
			dp[i & 1][j] = (dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1] + dp[(i - 1) & 1][j + 1]) % 1000000007;
		}
	}

	cout << dp[n & 1][0];

	return 0;
}
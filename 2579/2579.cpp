#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	long dp[310][2];
	long list[310];

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
		dp[i][1] = 0;
		list[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		list[i] = t;
	}

	dp[1][0] = list[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + list[i];
		dp[i][1] = dp[i - 1][0] + list[i];
	}

	cout << max(dp[n][0], dp[n][1]);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	long long n, mm, i, j;
	cin >> n >> mm;
	long long **dp = new long long*[n + 1];
	long long *c = new long long[n + 1];
	long long *m = new long long[n + 1];

	long long cost_sum = 0;
	for (i = 1; i <= n; i++) {
		long long t;
		cin >> t;
		m[i] = t;

	}

	for (i = 1; i <= n; i++) {
		long long t;
		cin >> t;
		c[i] = t;
		cost_sum += t;
	}

	for (i = 0; i <= n; i++) {
		dp[i] = new long long[cost_sum + 1];
		for (j = 0; j <= cost_sum; j++) {
			dp[i][j] = 0;
		}
	}

	long long min_cost = LONG_MAX;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= cost_sum; j++) {
			dp[i][j] = max((j >= c[i] ? dp[i - 1][j - c[i]] + m[i] : 0), dp[i - 1][j]);
			if (dp[i][j] >= mm && min_cost > j) {
				min_cost = j;
			}
		}
	}

	cout << min_cost;

	return 0;
}

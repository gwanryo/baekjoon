#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int i, j, n;
	cin >> n;

	int *test = new int[n + 1];
	vector<int> prime;

	for (i = 1; i <= n; i++) {
		test[i] = i;
	}

	for (i = 2; i <= n; i++) {
		if (test[i] == 0) continue;
		else prime.push_back(i);

		for (j = i * 2; j <= n; j += i) {
			test[j] = 0;
		}
	}

	int sum = 0, cnt = 0, s = 0, e = 0;
	while (s < prime.size() || e < prime.size()) {
		if (sum < n) {
			if (e >= prime.size()) break;
			sum += prime[e++];
		}
		else {
			if (s >= prime.size()) break;
			sum -= prime[s++];
		}

		if (sum == n) cnt++;
	}

	cout << cnt;
	return 0;
}
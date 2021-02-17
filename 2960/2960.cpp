#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n, k, i, j, m = 0;

	cin >> n >> k;

	vector<int> prime(n + 1);
	for (i = 1; i <= n; i++) {
		prime[i] = i;
	}

	for (i = 2; i <= n; i++) {
		if (prime[i] == 0) continue;

		for (j = i; j <= n; j += i) {
			if (prime[j] != 0 && k-- == 1) {
				cout << prime[j];
				break;
			}

			prime[j] = 0;
		}

		if (k == 0) break;
	}

	return 0;
}
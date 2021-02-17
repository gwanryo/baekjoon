#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define max 1000000

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int i, j;

	int *test = new int[max + 1];
	vector<int> prime;

	for (i = 1; i <= max; i++) {
		test[i] = i;
	}

	for (i = 2; i <= max; i++) {
		if (test[i] == 0) continue;
		else prime.push_back(i);

		for (j = i * 2; j <= max; j += i) {
			test[j] = 0;
		}
	}

	int n = 1;
	while (n != 0) {
		cin >> n;
		if (n == 0) break;

		int pmax = prime.size();
		for (i = 0; i < prime.size(); i++) {
			if (prime[i] > n) {
				pmax = i;
				break;
			}
		}

		bool flag = false;
		for (i = 0; i <= pmax; i++) {
			for (j = pmax; j >= i; j--) {
				if (prime[i] + prime[j] == n) {
					flag = true;
					cout << n << " = " << prime[i] << " + " << prime[j] << "\n";
					break;
				}
			}
			if (flag) break;
		}

		if (!flag) cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}
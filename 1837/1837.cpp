#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool divide(string p, int prime) {
	int r = 0;
	for (int i = 0; i < p.length(); i++) {
		r = (r * 10 + (p[i] - '0')) % prime;
	}
	return (r ? false : true);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	string p;
	int i, j, k;
	cin >> p >> k;

	int *test = new int[k];
	vector<int> prime;

	for (i = 1; i < k; i++) {
		test[i] = i;
	}

	for (i = 2; i < k; i++) {
		if (test[i] == 0) continue;
		else prime.push_back(i);

		for (j = i * 2; j < k; j += i) {
			test[j] = 0;
		}
	}

	delete test;

	bool flag = false;
	for (i = 0; i < prime.size(); i++) {
		if (divide(p, prime[i])) {
			flag = true;
			cout << "BAD " << prime[i];
			break;
		}
	}

	if (!flag) cout << "GOOD";

	return 0;
}
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

	int n, c, i, j;
	cin >> n;

	vector<int> number;

	cin >> c;

	f[0] = 1;
	for (i = 1; i < 21; i++) {
		f[i] = f[i - 1] * i;
	}

	if (c % 2) {
		long long k;
		cin >> k;
		for (i = 0; i < n; i++)
			number.push_back(i + 1);

		vector<int> answer;
		k--;
		for (i = n - 1; i >= 0; i--) {
			int d = k / f[i];
			answer.push_back(number[d]);
			number.erase(number.begin() + d);
			k %= f[i];
		}

		for (auto n : answer) {
			cout << n << " ";
		}
	} else {
		long long answer = 0;
		vector<int> number;

		for (i = 0; i < n; i++) {
			int t;
			cin >> t;
			number.push_back(t);
		}

		for (i = 0; i < n - 1; i++) {
			int count = number[i] - 1;
			for (j = 0; j <= i; j++) {
				if (number[j] < number[i]) count--;
			}
			if (count > 0)
				answer += count * f[n - i - 1];
		}

		cout << answer + 1;
	}

	return 0;
}
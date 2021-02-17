#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
vector<int> num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	int i, j;
	long **m = new long*[n + 1];
	for (i = 0; i < n + 1; i++) {
		m[i] = new long[21];
		for (j = 0; j < 21; j++) {
			m[i][j] = 0;
		}
	}

	for (i = 0; i < n - 1; i++) {
		int p;
		cin >> p;
		num.push_back(p);
	}

	long result;
	cin >> result;

	m[1][num[0]] = 1;
	for (i = 1; i < n - 1; i++) {
		for (j = 0; j <= 20; j++) {
			if (m[i][j] != 0) {
				if (num[i] + j <= 20) {
					m[i + 1][num[i] + j] += m[i][j];
				}

				if (j - num[i] >= 0) {
					m[i + 1][j - num[i]] += m[i][j];
				}
			}
		}
	}

	cout << m[n - 1][result];

	return 0;
}
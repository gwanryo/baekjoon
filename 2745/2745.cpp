#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, i;
	long long sum = 0;
	long long multi = 1;
	string m;
	cin >> m >> n;

	for (i = m.length()-1; i >= 0; i--) {
		int sm;

		if (m[i] - '0' < 10 && m[i] - '0' >= 0) {
			sm = m[i] - '0';
		}
		else {
			sm = (m[i] - 'A') + 10;
		}

		sum += sm * multi;
		multi *= n;
	}

	cout << sum;

	return 0;
}
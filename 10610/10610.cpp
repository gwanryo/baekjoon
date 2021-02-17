#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	string n;
	cin >> n;

	vector<int> number;

	int sum = 0;
	bool flag = false;
	for (int i = 0; i < n.length(); i++) {
		int m = n[i] - '0';
		if (m == 0) flag = true;
		sum += m;
		number.push_back(m);
	}

	if (sum % 3 == 0 && flag) {
		sort(number.begin(), number.end(), desc);
		for (int i = 0; i < number.size(); i++) {
			cout << number[i];
		}
	} else {
		cout << -1;
	}

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, t, min_n = 1000001, max_n = -1000001;
	cin >> n;
	
	for (i = 0; i < n; i++) {
		cin >> t;
		if (min_n > t) min_n = t;
		if (max_n < t) max_n = t;
	}

	cout << min_n << " " << max_n;
}
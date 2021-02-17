#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long x, y;
	cin >> x >> y;
	long z = (y * 100) / x;
	
	if (z >= 99) {
		cout << -1;
	} else {
		long a = (x * (z + 1) - 100 * y);
		long b = 99 - z;
		cout << ((a % b > 0)? (a / b) + 1 : a / b);
	}
	return 0;
}
#include <iostream>
using namespace std;

int gcd(int x, int y) {
	while (y) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int g = gcd(a * d + b * c, b * d);
	cout << (a * d + b * c) / g << " " << (b * d) / g;

	return 0;
}
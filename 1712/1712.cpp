#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << ((c - b > 0) ? (int)ceil(a / (c - b)) + 1 : -1);
}
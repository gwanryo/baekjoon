#include <iostream>
using namespace std;

int main() {
	int n, m = 2;
	cin >> n;
	
	while(m <= n) {
		if (n % m == 0) {
			n /= m;
			cout << m << endl;
		} else {
			m++;
		}
	}
	
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	long a = 1;
	
	for(int i = n; i >= n - k + 1; i--) {
		a *= i;
	}
	
	for(int i = 1; i <= k; i++) {
		a /= i;
	}
	
	cout << a;
	
	return 0;
}
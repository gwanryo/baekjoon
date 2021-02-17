#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	long **c = new long*[n + 1];
	
	for(int i = 0; i <= n; i++) {
		c[i] = new long[i + 1];
	}
	
	c[1][0] = 1, c[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		c[i][0] = 1, c[i][i] = 1;
		for(int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 10007;
		}
	}
	
	cout << c[n][k] % 10007;
	
	return 0;
}
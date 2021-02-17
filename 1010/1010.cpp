#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, k;
	cin >> n;
	
	long long **c = new long long*[31];
	
	for(int i = 0; i <= 30; i++) {
		c[i] = new long long[i + 1];
	}
	
	c[1][0] = 1, c[1][1] = 1;
	for(int i = 2; i <= 30; i++) {
		c[i][0] = 1, c[i][i] = 1;
		for(int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y) swap(x, y);
		cout << c[x][y] << "\n";
	}
	
	return 0;
}
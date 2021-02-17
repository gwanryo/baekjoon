#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	long long **c = new long long*[n + m + 1];
	
	for(int i = 0; i <= n + m; i++) {
		c[i] = new long long[i + 1];
	}
	
	c[1][0] = 1, c[1][1] = 1;
	for(int i = 2; i <= n + m; i++) {
		c[i][0] = 1;
		for(int j = 1; j < i; j++) {
			c[i][j] = min(c[i - 1][j - 1] + c[i - 1][j], (long long)1e9);
		}
		c[i][i] = 1;
	}
	
	int t = n + m;
	if (c[t][m] < k) {
		cout << -1;
		return 0;
	}
	
	string s = "";
	
	for(int i = 0; i < t; i++) {
		if (n <= 0) {
			for(int j = 0; j < m; j++) s += 'z';
			break;
		}
		
		if (m <= 0) {
			for(int j = 0; j < n; j++) s += 'a';
			break;
		}
		
		if (c[n + m - 1][m] < k) {
			s += 'z';
			k -= c[n + m - 1][m];
			m--;
		} else {
			s += 'a';
			n--;
		}
	}
	
	cout << s;
	
	return 0;
}
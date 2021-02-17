#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, i, j;
	cin >> n;

	int *g = new int[200001];
	int *f = new int[200001];
	
	for (j = 0; j < n; j++) {
		map<string, int> t;
		string x, y;
		int ct = 1;

		cin >> m;

		for (i = 0; i < 2 * m + 1; i++) {
			g[i] = i;
			f[i] = 1;
		}

		for (i = 0; i < m; i++) {
			cin >> x >> y;
			if (x > y) swap(x, y);
			
			if (t.count(x) == 0)
				t[x] = ct++;

			if (t.count(y) == 0)
				t[y] = ct++;
				
			int nx = t[x], ny = t[y];
			
			while(nx != g[nx]) nx = g[nx];
			while(ny != g[ny]) ny = g[ny];
			
			if (nx != ny) {
				g[nx] = ny;
				f[ny] += f[nx];
				f[nx] = 1;
			}
			
			cout << f[ny] << "\n";
		}
	}

	return 0;
}
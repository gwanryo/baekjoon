#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> number;
vector<int> sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int t;
	cin >> t;
	number.push_back(t);
	sum.resize(n + 1);
	sum[0] = t;

	for (int i = 1; i < n; i++) {
		cin >> t;
		sum[i] = sum[i - 1] + t;
		number.push_back(t);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x > y) swap(x, y);
		if (x == 0) cout << sum[y] << "\n";
		else cout << sum[y] - sum[x - 1] << "\n";
	}

	return 0;
}
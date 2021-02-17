#include <iostream>
#include <algorithm>
using namespace std;
int tri[500][500];
long maxx[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int t;
			cin >> t;
			tri[i][j] = t;

			if (j == 0) {
				if (i == 0) maxx[i][j] = t;
				else maxx[i][j] = maxx[i - 1][j] + t;
			} else if (j == i) {
				maxx[i][j] = maxx[i - 1][j - 1] + t;
			} else {
				maxx[i][j] = max(maxx[i - 1][j], maxx[i - 1][j - 1]) + t;
			}
		}
	}

	int tmax = 0;
	for (int i = 0; i < n; i++) {
		if (tmax < maxx[n - 1][i]) tmax = maxx[n - 1][i];
	}

	cout << tmax;

	return 0;
}
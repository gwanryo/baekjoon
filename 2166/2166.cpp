#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	double *x = new double[n + 1];
	double *y = new double[n + 1];

	int i = 0;

	for (i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	long double sum = 0;
	x[n] = x[0];
	y[n] = y[0];

	for (i = 0; i < n; i++) {
		sum += ((x[i] * y[i + 1]) - (x[i + 1] * y[i])) * 0.5;
	}

	cout << fixed;
	cout.precision(1);
	cout << fabs(sum);

	return 0;
}
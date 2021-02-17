#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int ax, bx, cx;
	int ay, by, cy;

	cin >> ax >> ay >> bx >> by >> cx >> cy;

	int k = (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);

	if (k > 0) cout << 1;
	else if (k < 0) cout << -1;
	else cout << 0;

	return 0;
}
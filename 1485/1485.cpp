#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll length(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	ll n, i;
	cin >> n;

	for (i = 0; i < n; i++) {
		pll a, b, c, d;
		cin >> a.first >> a.second >> b.first >> b.second
			>> c.first >> c.second >> d.first >> d.second;

		vector<ll> square;
		square.push_back(length(a, b));
		square.push_back(length(a, c));
		square.push_back(length(a, d));
		square.push_back(length(b, c));
		square.push_back(length(b, d));
		square.push_back(length(c, d));

		sort(square.begin(), square.end());

		if (square[0] == square[1] && square[1] == square[2] && square[2] == square[3] &&
			square[4] == square[5])
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool divide(string p, int prime) {
	int r = 0;
	for (int i = 0; i < p.length(); i++) {
		r = (r * 10 + 1) % prime;
	}
	return (r ? false : true);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	string p;
	int i, n;

	while (cin >> n) {
		p = "1";
		while(1) {
			if (divide(p, n)) {
				cout << p.length() << "\n";
				break;
			}
			p.append("1");
		}
	}

	return 0;
}
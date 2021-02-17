#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int e, s, m;
	cin >> e >> s >> m;
	
	int i = 1;
	while (true) {
		if ((i - e) % 15 == 0 && (i - s) % 28 == 0 && (i - m) % 19 == 0) {
			cout << i;
			return 0;
		}
		i++;
	}

	return 0;
}
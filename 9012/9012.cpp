#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> ca;
	vector<int> a;

	int k;
	cin >> k;

	string c;
	getline(cin, c);

	for (int j = 0; j < k; j++) {
		bool yn = true;

		getline(cin, c);
		for (int i = 0; i < c.length(); i++) {
			ca.push_back(c[i]);
		}

		for (int i = 0; i < ca.size(); i++) {
			if (ca[i] == 40) {
				a.push_back(ca[i]);
			}
			else if (ca[i] == 41) {
				if (!a.empty() && a.back() == 40) {
					a.pop_back();
				} else {
					yn = false;
					break;
				}
			}
		}

		if (yn && a.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		a.clear(), ca.clear();
	}

	return 0;
}
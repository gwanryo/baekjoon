#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> ca;
	vector<int> a;

	string c;
	getline(cin, c);
	for (int i = 0; i < c.length(); i++) {
		ca.push_back(c[i]);
	}

	int temp = 1, result = 0;
	for (int i = 0; i < ca.size(); i++) {
		if (ca[i] == 40) {
			temp *= 2;
			a.push_back(ca[i]);
		}
		else if (ca[i] == 91) {
			temp *= 3;
			a.push_back(ca[i]);
		}
		else if (ca[i] == 41) {
			if (ca[i - 1] == 40)
				result += temp;

			if (!a.empty() && a.back() == 40) {
				a.pop_back();
				temp /= 2;
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (ca[i] == 93) {
			if (ca[i - 1] == 91)
				result += temp;

			if (!a.empty() && a.back() == 91) {
				a.pop_back();
				temp /= 3;
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}

	if (a.empty())
		cout << result;
	else
		cout << 0;

	return 0;
}
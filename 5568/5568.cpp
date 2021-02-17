#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
vector<string> num;
set<string> str;

void dfs(bool *visit, int start, int length, string result) {
	result += num[start];
	visit[start] = true;
	length--;

	if (length == 0) {
		str.insert(result);
		return;
	}

	for (int i = 0; i < num.size(); i++) {
		if (!visit[i]) {
			dfs(visit, i, length, result);
			visit[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	bool *visit = new bool[n];

	int i;
	for (i = 0; i < n; i++) {
		string p;
		cin >> p;
		num.push_back(p);
	}

	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) visit[j] = false;
		string s;
		dfs(visit, i, k, s);
	}

	cout << str.size();

	return 0;
}
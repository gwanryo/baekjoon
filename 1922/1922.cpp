#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct job {
	long pre, post, cost;

	job(int _pre, int _post, int _cost) : pre(_pre), post(_post), cost(_cost) {}
	inline bool operator < (const job& j) const { return (cost < j.cost); };
	inline bool operator > (const job& j) const { return (cost > j.cost); };
	inline bool operator <= (const job& j) const { return (cost <= j.cost); };
	inline bool operator >= (const job& j) const { return (cost >= j.cost); };
	inline bool operator == (const job& j) const { return (pre == j.pre && post == j.post && cost == j.cost); };
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, i, j;
	cin >> n >> m;

	vector<job> v;
	int *parent = new int[n + 1];

	for (i = 1; i < n + 1; i++) parent[i] = i;

	int from, to, cost;
	for (i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		v.push_back(job(from, to, cost));
	}

	sort(v.begin(), v.end());

	long total_cost = 0;
	for (i = 0; i < v.size(); i++) {
		int x = v[i].pre;
		int y = v[i].post;

		while (x != parent[x]) x = parent[x];
		while (y != parent[y]) y = parent[y];

		if(x != y) {
			parent[x] = y;
			total_cost += v[i].cost;
		}
	}

	cout << total_cost;
	return 0;
}
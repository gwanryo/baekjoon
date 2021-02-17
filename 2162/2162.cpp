#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, p> pp;
vector<pp> line;
vector<vector<int>> meet;
bool *visit;

long long ccw(p a, p b) {
	return a.first * b.second - b.first * a.second;
}

int ccw(p a, p b, p c) {
	long long result = \
		ccw({ b.first - a.first, b.second - a.second }, { c.first - a.first, c.second - a.second });

	if (result > 0) return 1;
	else if (result < 0) return -1;
	else return 0;
}

bool cross(pp x, pp y) {
	p a = x.first, b = x.second;
	p c = y.first, d = y.second;

	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	// ab와 cd가 둘 다 0이라면, 
	// ab를 무한히 늘린 직선 상에 c나 d가 존재한다는 것이다.
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		
		// 만약 만나는 선분이라 가정하면,
		// a, b 중 큰 점보다 c, d 중 작은 점의 크기는 작아야 되고,
		// a, b 중 작은 점보다 c, d 중 큰 점의 크기는 커야 된다.
		// 만족하지 않는다면, 지나지 않는 평행한 선분이다.
		// min(c, d) <= max(a, b) && min(a, b) <= max(c, d)
		return c <= b && a <= d;
	}

	// ab와 cd가 모두 0보다 작다면, 두 선분은 만나는 것이 맞다
	// 선분 ab에서 c와 d가 반대에 위치하고,
	// 선분 cd에서 a와 b가 반대에 위치하기 때문이다.
	return (ab <= 0 && cd <= 0);
}

int get_group(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	// 이 그룹에 자기 자신을 포함하므로 1로 시작
	int number = 1;

	while (!q.empty()) {
		int index = q.front(); q.pop();

		for (auto i : meet[index]) {
			if (!visit[i]) {
				q.push(i);
				number++;
				visit[i] = true;
			}
		}
	}

	return number;
}

int main() {
	int n;
	cin >> n;
	line.resize(n);
	visit = new bool[n];

	int i, j;
	for (i = 0; i < n; i++) {
		cin >> line[i].first.first >> line[i].first.second \
			>> line[i].second.first >> line[i].second.second;

		visit[i] = false;
	}

	meet.resize(n);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (cross(line[i], line[j])) {
				meet[i].push_back(j);
				meet[j].push_back(i);
			}
		}
	}

	int number = 0, maximum = INT_MIN;
	for (i = 0; i < n; i++) {
		if (!visit[i]) {
			number++;
			maximum = max(maximum, get_group(i));
		}
	}

	cout << number << "\n" << maximum;
	return 0;
}
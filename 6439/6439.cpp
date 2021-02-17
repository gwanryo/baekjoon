#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> pp;

int ccw(p a, p b, p c) {
	p v1 = { b.first - a.first, b.second - a.second };
	p v2 = { c.first - a.first, c.second - a.second };

	ll result = v1.first * v2.second - v1.second * v2.first;

	if (result > 0) return 1;
	else if (result < 0) return -1;
	else return 0;
}

bool cross(pp xx, pp yy) {
	p a = xx.first, b = xx.second;
	p c = yy.first, d = yy.second;

	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);

	// ab와 cd가 둘 다 0이라면, 
	// ab를 무한히 늘린 직선 상에 c나 d가 존재한다는 것이다.
	if (ab == 0 && cd == 0) {
		if (c.first == d.first) {
			// 직사각형에서 c, d가 세로 직선일 때,
			// a나 b의 y 좌표가 c, d y 좌표 바깥쪽에 있으면
			// 만나지 않는 점이다.
			if (max(a.second, b.second) < min(c.second, d.second) || \
				max(c.second, d.second) < min(a.second, b.second)) {
				return 0;
			}
		} else if (c.second == d.second) {
			// 직사각형에서 c, d가 가로 직선일 때,
			// a나 b의 x 좌표가 c, d x 좌표 바깥쪽에 있으면
			// 만나지 않는 점이다.
			if (max(a.first, b.first) < min(c.first, d.first) || \
				max(c.first, d.first) < min(a.first, b.first)) {
				return 0;
			}
		}
	}

	// ab와 cd가 모두 0보다 작다면, 두 선분은 만나는 것이 맞다
	// 선분 ab에서 c와 d가 반대에 위치하고,
	// 선분 cd에서 a와 b가 반대에 위치하기 때문이다.
	return (ab <= 0 && cd <= 0);
}

int main() {
	int n;
	cin >> n;

	for (int j = 0; j < n; j++) {
		pp line;
		cin >> line.first.first >> line.first.second \
			>> line.second.first >> line.second.second;
		if (line.first.first < line.second.first) {
			swap(line.first, line.second);
		}

		p lb, lt, rt, rb;
		cin >> lt.first >> lt.second >> rb.first >> rb.second;
		if (lt.first > rb.first) swap(lt.first, rb.first);
		if (lt.second < rb.second) swap(lt.second, rb.second);

		lb.first = lt.first; lb.second = rb.second;
		rt.first = rb.first; rt.second = lt.second;

		if (lb.first <= line.first.first && line.first.first <= rt.first && \
			lb.second <= line.first.second && line.first.second <= rt.second) {
			cout << "T\n";
		} else if (lb.first <= line.second.first && line.second.first <= rt.first && \
			lb.second <= line.second.second && line.second.second <= rt.second) {
			cout << "T\n";
		} else {
			bool flag = false;
			if (cross(line, { lt, rt })) flag = true;
			if (cross(line, { lt, lb })) flag = true;
			if (cross(line, { lb, rb })) flag = true;
			if (cross(line, { rb, rt })) flag = true;

			if (flag) cout << "T\n";
			else cout << "F\n";
		}
	}

	return 0;
}
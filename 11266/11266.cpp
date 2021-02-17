#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int number = 1, root;

int dfs(vector<int> *graph, int *visit, bool *cut, int index) {
	visit[index] = number++;
	int low = visit[index];
	int child = 0;

	for (int i = 0; i < graph[index].size(); i++) {
		// 자식 노드를 방문한 적이 있으면,
		if (visit[graph[index][i]]) {
			low = min(low, visit[graph[index][i]]);
			continue;
		}

		// 자식 노드를 방문한 적이 없으면
		// 루트 노드의 자식 수를 세고,
		child++;

		int leaf_low = dfs(graph, visit, cut, graph[index][i]);

		// 지금 탐색중인 노드가 루트 노드가 아니고 (따로 처리해야 함)
		// 현 노드의 low 값보다 자식 노드의 low 값이 크면 현 노드를
		// 무조건 지나간다는 이야기이다.
		if (root != index && leaf_low >= visit[index]) {
			cut[index] = true;
		}

		// 현 노드의 low 값과 자식 노드의 low 값 중
		// 최소값으로 현 노드의 low 값을 갱신해준다.
		low = min(low, leaf_low);
	}

	// 마지막으로, 루트 노드의 자식 수가 2 이상이었으면,
	// 단절점으로 체크해준다.
	if (root == index && child >= 2)
		cut[index] = true;

	return low;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int i, j, x, y;
	vector<int> *graph = new vector<int>[v + 1];
	int *visit = new int[v + 1];
	bool *cut = new bool[v + 1];

	for (i = 0; i < e; i++) {
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (i = 1; i <= v; i++) visit[i] = 0, cut[i] = false;

	for (i = 1; i <= v; i++) {
		if (!visit[i]) {
			root = i;
			dfs(graph, visit, cut, i);
		}
	}

	int cnt = 0;
	for (i = 1; i <= v; i++) {
		if (cut[i])
			cnt++;
	}
	cout << cnt << "\n";

	for (i = 1; i <= v; i++) {
		if (cut[i])
			cout << i << " ";
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define vpii vector<pair<int, int>>
int number = 1;

int dfs(vector<int> *graph, int *visit, vpii &cut, int index, int parent) {
	visit[index] = number++;
	int low = visit[index];

	for (int i = 0; i < graph[index].size(); i++) {
		// 부모 노드로 가지 않는다
		if (graph[index][i] == parent)
			continue;

		// 자식 노드를 방문한 적이 있으면,
		if (visit[graph[index][i]]) {
			low = min(low, visit[graph[index][i]]);
			continue;
		}

		// 자식 노드를 방문한 적이 없으면
		int leaf_low = dfs(graph, visit, cut, graph[index][i], index);

		// 지금 탐색중인 노드가 루트 노드가 아니고 (따로 처리해야 함)
		// 현 노드의 low 값보다 자식 노드의 low 값이 크면 현 노드를
		// 무조건 지나간다는 이야기이다.
		if (leaf_low > visit[index]) {
			cut.push_back({ min(index, graph[index][i]), max(index, graph[index][i]) });
		}

		// 현 노드의 low 값과 자식 노드의 low 값 중
		// 최소값으로 현 노드의 low 값을 갱신해준다.
		low = min(low, leaf_low);
	}

	return low;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int i, x, y;
	vector<int> *graph = new vector<int>[v + 1];
	int *visit = new int[v + 1];
	vector<pair<int, int>> cut;

	for (i = 0; i < e; i++) {
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (i = 1; i <= v; i++) visit[i] = 0;

	for (i = 1; i <= v; i++) {
		if (!visit[i]) {
			dfs(graph, visit, cut, i, 0);
		}
	}

	cout << cut.size() << "\n";
	sort(cut.begin(), cut.end());

	for (i = 0; i < cut.size(); i++) {
		cout << cut[i].first << " " << cut[i].second << "\n";
	}

	return 0;
}
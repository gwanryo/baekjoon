#include <iostream>
#include <vector>
using namespace std;
#define nodes 2
vector<int> trace;

void preorder(int** map, int ptr) {
	if (ptr == -1) return;
	trace.push_back(ptr);
	preorder(map, map[ptr][0]);
	preorder(map, map[ptr][1]);
}

void inorder(int** map, int ptr) {
	if (ptr == -1) return;
	inorder(map, map[ptr][0]);
	trace.push_back(ptr);
	inorder(map, map[ptr][1]);
}

void postorder(int **map, int ptr) {
	if (ptr == -1) return;
	postorder(map, map[ptr][0]);
	postorder(map, map[ptr][1]);
	trace.push_back(ptr);
}

int main() {
	int n;
	cin >> n;

	int root, left, right, i, j;
	char ch;

	int **map = new int*[n];
	for (i = 0; i < n; i++) {
		map[i] = new int[nodes];

		for (j = 0; j < nodes; j++) {
			map[i][j] = -1;
		}
	}

	for (i = 0; i < n; i++) {
		getchar(), ch = getchar();
		root = (int)ch - 'A';

		getchar(), ch = getchar();
		left = (int)ch - 'A';

		getchar(), ch = getchar();
		right = (int)ch - 'A';

		if (left != -19)
			map[root][0] = left;

		if (right != -19)
			map[root][1] = right;
	}

	preorder(map, 0);
	for (i = 0; i < trace.size(); i++) {
		cout << (char)(trace[i] + (int)'A');
	}
	cout << endl;

	trace.clear();
	inorder(map, 0);
	for (i = 0; i < trace.size(); i++) {
		cout << (char)(trace[i] + (int)'A');
	}
	cout << endl;

	trace.clear();
	postorder(map, 0);
	for (i = 0; i < trace.size(); i++) {
		cout << (char)(trace[i] + (int)'A');
	}

	return 0;
}
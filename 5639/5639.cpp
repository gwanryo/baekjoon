#include <iostream>
using namespace std;

struct node {
	node* parent = nullptr, *left = nullptr, *right = nullptr;
	int value;
};

void add(node *n, int x) {
	if (n->value > x) {
		if (n->left == nullptr) {
			node *child = new node;
			child->parent = n;
			child->value = x;
			n->left = child;
		}
		else {
			add(n->left, x);
		}
	}
	else if (n->value < x) {
		if (n->right == nullptr) {
			node *child = new node;
			child->parent = n;
			child->value = x;
			n->right = child;
		}
		else {
			add(n->right, x);
		}
	}
}

void postorder(node *n) {
	if (n == nullptr) return;
	postorder(n->left);
	postorder(n->right);
	cout << n->value << endl;
}

int main() {
	int x;
	cin >> x;

	node *root = new node;
	root->value = x;

	while (cin >> x) {
		add(root, x);
	}

	postorder(root);

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string line;
	string delimiter = " ";
	
	vector<string> stack;
	for(int i = 0; i <= n; i++) {
		getline(cin, line);
		
		string command, number;
		if (line.find(delimiter) != string::npos) {
			command = line.substr(0, line.find(delimiter));
			number = line.substr(line.find(delimiter) + 1, line.length());
		} else {
			command = line;
		}
		
		if (command == "push") {
			stack.push_back(number);
		} else if (command == "pop") {
			if (stack.size() > 0) {
				cout << stack.front() << endl;
				stack.erase(stack.begin());
			} else {
				cout << -1 << endl;
			}
		} else if (command == "size") {
			cout << stack.size() << endl;
		} else if (command == "empty") {
			cout << ((stack.size() == 0) ? 1 : 0) << endl;
		} else if (command == "front") {
			if (stack.size() > 0) {
				cout << stack.front() << endl;
			} else {
				cout << -1 << endl;
			}
		} else if (command == "back") {
			if (stack.size() > 0) {
				cout << stack.back() << endl;
			} else {
				cout << -1 << endl;
			}
		}
		
	}
	
	return 0;
}
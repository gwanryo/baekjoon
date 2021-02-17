#include <iostream>
using namespace std;

int main() {
	int n, i;
	long s;
	cin >> n >> s;
	int* a = new int[n];
	long sum = 0;
	long c = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(i = 0; i < n; i++) {
		if(a[i] == s) c++;
	}
	
	// i is number of members in group.
	for(i = 2; i <= n; i++) {
		// sum of 0 ~ i
		for(int j = 0; j < i; j++) {
			sum += a[j];
		}
		
		if (sum == s) c++;
		
		// push group (0~i) to group (n-i+1~n)
		for(int j = 0; j < n - i; j++) {
			sum -= a[j];
			sum += a[i + j];
			
			//cout << j << " " << i + j << " = " << sum << endl;
			
			if (sum == s) c++;
		}
		
		sum = 0;
	}
	
	cout << c;
}
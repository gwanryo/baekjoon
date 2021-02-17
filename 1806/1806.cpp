#include <iostream>
using namespace std;

int main() {
	long n, s;
	cin >> n >> s;
	long i;
	long *a = new long[n];
	long sum = 0, left = 0, right = 0, min = n;
	bool flag = false;
	
	for(i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	while(true) {
		if(sum >= s) {
			if(right - left < min) min = right - left;
			sum -= a[left++];
			flag = true;
		} else {
			sum += a[right++];
		}
		if (right >= n && sum < s) break;
	}
	
	if(flag) cout << min;
	else cout << 0;
}
#include <iostream>
using namespace std;

int main() {
	long n, m;
	cin >> n >> m;
	long *a = new long[n];
	long mid, start = 0, end = 0;
	long i;
	
	for(i = 0; i < n; i++) {
		cin >> a[i];
		if (end < a[i]) end = a[i];
	}
	
	long sum = 0, last_mid = start;
	while(start <= end) {
		mid = (start + end) / 2;
		//cout << start << " " << mid << " " << end;
		
		sum = 0;
		for(i = 0; i < n; i++) {
			if (a[i] > mid) sum += a[i] - mid;
		}
		
		//cout << " " << sum << endl;
		
		if(sum > m) {
			start = mid + 1;
			
			if(last_mid < mid) {
				last_mid = mid;
			}
		} else if (sum < m) {
			end = mid - 1;
		} else {
			last_mid = mid;
			break;
		}
	}
	
	cout << last_mid;
}
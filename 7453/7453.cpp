#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	
	long long *a = new long long[n];
	long long *b = new long long[n];
	long long *c = new long long[n];
	long long *d = new long long[n];
	
	
	for(i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	long long *ab = new long long[n*n];
	long long *cd = new long long[n*n];
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			ab[n * i + j] = a[i] + b[j];
			cd[n * i + j] = c[i] + d[j];
		}
	}
	
	delete a, b, c, d;
	
	sort(ab, ab + n*n);
	sort(cd, cd + n*n);
	
	long left = 0, right = n*n - 1, temp;
	long long sum = 0, cnt = 0;
	
	while(left < n*n && right >= 0) {
		sum = ab[left] + cd[right];
		
		if(sum > 0) {
			temp = right;
			while(right >= 0 && cd[right] == cd[temp]) right--;
		} else if(sum < 0) {
			temp = left;
			while(left < n*n && ab[left] == ab[temp]) left++;
		} else {
			long cl = 0, cr = 0;
			
			temp = left;
			while(left < n*n && ab[left] == ab[temp]){
				left++;
				cl++;
			}
			
			temp = right;
			while(right >= 0 && cd[right] == cd[temp]){
				right--;
				cr++;
			}
			
			cnt += cl * cr;
		}
	}
	
	cout << cnt;
	return 0;
}
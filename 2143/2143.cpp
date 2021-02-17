#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, i, j;
	long t, c = 0;
	
	cin >> t;
	
	cin >> n;
	vector<int> a(n);
	
	cin >> a[0];
	for(i = 1; i < n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	
	vector<int> sa;
	for(i = 1; i <= n; i++) {
		sa.push_back(a[i - 1]);
		
		for(j = i; j < n; j++)
			sa.push_back(a[j] - a[j - i]);
	}
	
	cin >> m;
	vector<int> b(m);
	
	cin >> b[0];
	for(i = 1; i < m; i++) {
		cin >> b[i];
		b[i] += b[i - 1];
	}
	
	vector<int> sb;
	for(i = 1; i <= m; i++) {
		sb.push_back(b[i - 1]);
		
		for(j = i; j < m; j++)
			sb.push_back(b[j] - b[j - i]);
	}
	
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	
	long left = 0, right = sb.size() - 1, temp = 0;
	long sum = 0;
	
	while (left < sa.size() && right >= 0) {
		sum = sa[left] + sb[right];
		
		if (sum < t) {
			temp = left;
			while(left < sa.size() && sa[left] == sa[temp]) left++;
		} else if (sum > t) {
			temp = right;
			while(right >= 0 && sb[right] == sb[temp]) right--;
		} else {
			long ca = 0, cb = 0;
			
			temp = left;
			while(left < sa.size() && sa[left] == sa[temp]){
				left++;
				ca++;
			}
			
			temp = right;
			while(right >= 0 && sb[right] == sb[temp]){
				right--;
				cb++;
			}
			
			c += ca * cb;
		}
	}
	
	cout << c;
	return 0;
}
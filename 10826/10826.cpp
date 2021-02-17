#include <iostream>
using namespace std;
#define MAX 2090

int main() {
	int n;
	cin >> n;
	int **f= new int*[n+1];
	
	if(n == 0){
		cout << 0;
		return 0;
	}
	
	for(int i = 0; i <= n; i++) {
		f[i] = new int[MAX];
		
		for(int j = 0; j < MAX; j++) {
			f[i][j] = 0;
		}
	}
	
	f[1][MAX - 1] = 1;
	
	for(int i = 2; i <= n; i++) {
		for(int j = MAX - 1; j >= 0; j--) {
			if (f[i - 1][j] == 0 && f[i - 2][j] == 0) {
			
			} else {
				int sum = f[i - 1][j] + f[i - 2][j];
				if (sum > 9) {
					if (f[i][j] + sum - 10 > 9) {
						f[i][j] += sum - 20;
						f[i][j - 1]++;
					} else {
						f[i][j] += sum - 10;
					}
					f[i][j - 1]++;
				} else {
					if (f[i][j] + sum > 9) {
						f[i][j - 1]++;
						f[i][j] += sum - 10;
					} else {
						f[i][j] += sum;
					}
				}
			}
		}
	}
	
	bool flag = false;
	for(int i = 0; i < MAX; i++) {
		if (!flag && f[n][i] != 0) {
			flag = true;
		}
		
		if (flag) cout << f[n][i];
	}
	return 0;
}
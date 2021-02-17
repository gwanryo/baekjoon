#include <iostream>
using namespace std;
#define COL 3

int maxf(int x, int y) {
	return ((x > y) ? x : y);
}

int minf(int x, int y) {
	return ((x < y) ? x : y);
}

void cal_max(int* max, int x, int y, int z){
	int m0 = x + maxf(max[0], max[1]);
	int m1 = y + maxf(max[0], maxf(max[1], max[2]));
	int m2 = z + maxf(max[1], max[2]);
	
	max[0] = m0, max[1] = m1, max[2] = m2;
}

void cal_min(int* min, int x, int y, int z){
	// min[0] ==> min[0] + x, min[1] + x
	// min[1] ==> min[0] + y, min[1] + y, min[2] + y
	// min[2] ==> min[1] + z, min[2] + z
	
	int m0 = x + minf(min[0], min[1]);
	int m1 = y + minf(min[0], minf(min[1], min[2]));
	int m2 = z + minf(min[1], min[2]);
	
	min[0] = m0, min[1] = m1, min[2] = m2;
}

int main() {
	int n;
	cin >> n;
	int *min = new int[COL];
	int *max = new int[COL];
	int x, y, z;
	
	cin >> x >> y >> z;
	min[0] = x, min[1] = y, min[2] = z;
	max[0] = x, max[1] = y, max[2] = z;
	
	for(int i = 1; i < n; i++) {
		cin >> x >> y >> z;
		
		cal_min(min, x, y, z);
		cal_max(max, x, y, z);
	}
	
	cout << maxf(max[0], maxf(max[1], max[2])) << " " << minf(min[0], minf(min[1], min[2]));
	
	return 0;
}
#include <iostream>
using namespace std;

typedef struct matrix {
	unsigned long f[2][2];
} matrix;

matrix multiply(matrix a, matrix b) {
	matrix c;
	c.f[0][0] = a.f[0][0] * b.f[0][0] + a.f[0][1] * b.f[1][0];
	c.f[0][1] = a.f[0][0] * b.f[0][1] + a.f[0][1] * b.f[1][1];
	c.f[1][0] = a.f[1][0] * b.f[0][0] + a.f[1][1] * b.f[1][0];
	c.f[1][1] = a.f[1][0] * b.f[0][1] + a.f[1][1] * b.f[1][1];
	
	return c;
}

matrix power(matrix a, int n) {
	if (n > 1) {
		a = power(a, n / 2);
		a = multiply(a, a);
			
		if (n % 2) {
			matrix f = {1, 1, 1, 0};
			a = multiply(a, f);
		}
	}
	
	return a;
}

int main() {
	int n;
	cin >> n;
	matrix f1 = {1, 1, 1, 0};
	f1 = power(f1, n);
	if(n == 0) cout << 0;
	else cout << f1.f[0][1];
	return 0;
}
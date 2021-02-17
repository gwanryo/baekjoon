#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int w[101], num[51];
short wt[51][45001];
bool ps[51][45001]; 
 
int main()
{
    int n, i, j, k, s, avg;
 
	//while(cin >> n){
	cin >> n;
	
		s = 0;
		memset(w, 0x00, sizeof(w));
		memset(num, 0x00, sizeof(num));
		memset(ps, 0x00, sizeof(ps));
		memset(wt, 0x00, sizeof(wt));
	 
		for (i = 0; i < n; i++){
			cin >> w[i];
			s += w[i];
		}
			
		avg = s/2;
	 
		for (i = 0; i < n; i++){
			for (j = n/2-1; j >= 1; j--){
				for (k = 0; k < num[j]; k++){
					if (ps[j+1][wt[j][k] + w[i]] == false){
						ps[j+1][wt[j][k] + w[i]] = true;
						wt[j+1][num[j+1]++] = wt[j][k] + w[i];
					}
				}
			}
			if (ps[1][w[i]] == false){
				ps[1][w[i]] = true;
				wt[1][num[1]++] = w[i];
			}
		}
	 
		int minD = 999999999;
		int min = 0;
		for (i = 0; i < num[n/2]; i++){
			if (abs(wt[n/2][i] - avg) < minD){
				minD = abs(wt[n/2][i] - avg);
				min = i;
			}
		}
		
		cout << ((s - wt[n/2][min] > wt[n/2][min])?wt[n/2][min]:s - wt[n/2][min]) << " "
			<< ((s - wt[n/2][min] < wt[n/2][min])?wt[n/2][min]:s - wt[n/2][min]);
	//}
	
    return 0;
}
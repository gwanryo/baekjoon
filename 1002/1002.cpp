#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;

    double xa, ya, ra, xb, yb, rb, r, s;

    for(i=0;i<n;i++){
        cin >> xa >> ya >> ra >> xb >> yb >> rb;

        r = sqrt((ya-yb)*(ya-yb) + (xa-xb)*(xa-xb));
        s = ra > rb ? ra - rb : rb - ra;

        if(r == 0 && ra == rb) cout << "-1\n";
        else if( s < r && ra + rb > r ) cout << "2\n";
        else if( s == r || ra + rb == r ) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
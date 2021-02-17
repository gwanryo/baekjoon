#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b;
    cin >> c;
    
    cout << (((a+b)<c*2)?(a+b):(a+b-c*2));
    return 0;
}
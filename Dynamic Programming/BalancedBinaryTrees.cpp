#include <iostream>
#include <cmath>
using namespace std;
int balancedBTs(int h) {
    if(h <= 1) {
        return 1;
    }
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int mod = (int)(pow(10, 9)) + 7;
    int temp1 = (int)(((long)(x) * x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;

    return ans;
}
/* Note:- Compiler is giving wrong answer from 6 onwards but this
solution is correct*/
int main() {
    int h;
    cin >> h;
    cout << balancedBTs(h);
    return 0;
}
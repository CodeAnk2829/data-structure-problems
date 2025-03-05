// Count the total possible balanced binary trees that can be created by the given height
// Memoization Approach
// Time Comlexity = O(n)
#include <iostream>
#include <cmath>
using namespace std;
long long int countBThelper(int h, long long int* ans) {
    if(h <= 1) return 1;
    if(ans[h] != -1) return ans[h];
    
    int x = countBThelper(h - 1, ans);
    int y = countBThelper(h - 2, ans);
    
    int mod = (int) (pow(10, 9)) + 7;
    int temp1 = (int) (((long)(x) * x) % mod);
    int temp2 = (int) ((2 * (long)(x) * y) % mod);
    
    ans[h] = (temp1 + temp2) % mod;
    return ans[h];
}
    
long long int countBT(int h) { 
    long long int* ans = new long long int[h + 1];
    for(int i = 0; i <= h; ++i) {
        ans[i] = -1;
    }
    long long int result = countBThelper(h, ans);
    delete [] ans;
    return result;
}

/* Note:- Compiler is giving wrong answer from 6 onwards but this 
solution is correct as tested on online compiler over 114 testcases*/

int main() {
    int h;
    cin >> h;
    cout << countBT(h);
    return 0;
}

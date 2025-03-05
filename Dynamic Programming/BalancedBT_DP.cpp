// Dynamic Progaramming Approach
// Time Complexity = O(n)
// Space Complexity = O(n)
#include <iostream>
#include <cmath>
using namespace std;
long long int countBT(int h) {
    long long int* ans = new long long int[h + 1];
    for(int i = 0; i <= h; ++i) {
        ans[i] = -1;
    }
    ans[0] = ans[1] = 1;

    int mod = (int) (pow(10, 9)) + 7;
    for(int i = 2; i <= h; ++i) {
        int temp1 = (int) ((ans[i - 1] * ans[i - 1]) % mod);
        int temp2 = (int) ((2 * ans[i - 1] * ans[i - 2]) % mod);
        ans[i] = (temp1 + temp2) % mod;
    }

    long long int result = ans[h];
    delete [] ans;
    return result;
}

int main() {
    int h;
    cin >> h;
    cout << countBT(h);
    return 0;
}
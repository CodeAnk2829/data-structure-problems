// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
/* TIP: a, b, c <= 1e18
    doing a * b >= c will lead to an overflow situation
    Hence we should do, a >= ceil(c / b)
    but using a ceil function would not give best result because it gives 'double' not int
    so do: a >= ((c + b - 1) / b)

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    ll low = 1, high = 1e18;
    ll ans = 1;
    
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll rows = mid / h;
        ll cols = mid / w;
    
        if(cols > 0 && rows >= ((n + cols - 1) / cols)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
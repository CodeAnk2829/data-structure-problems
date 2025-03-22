#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if(a == b) {
        cout << "infinity";
    } else {
        int count = 0;
        // count the number of divisors of (a - b)
        for(int d = 1; d * d <= (a - b); d++) {
            if((a - b) % d == 0) {
                int firstDivisor = d;
                int secondDivisor = (a - b) / d;

                if(a % firstDivisor == b) count++;
                if(secondDivisor != d && a % secondDivisor == b) count++;
            }
        }

        cout << count;
    }

    return 0;
}
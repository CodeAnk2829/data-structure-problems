#include <bits/stdc++.h>
using namespace std;
int factmod(int n, int p)
{
    vector<long long int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i - 1] * i % p;

    int res = 1;
    while (n > 1)
    {
        if ((n / p) % 2)
            res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}
int main() {
    int n, x;
    cin >> n >> x;
    vector <int> v(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += factmod(v[i], 500001);
    }
    int temp = factmod(x, 500001);
    int ans = sum % temp;
    if(ans == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
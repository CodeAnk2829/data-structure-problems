#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x, n;
    cin >> x >> n;
    set<long long> taken;
    for (int i = 0; i < n; i++)
    {
        long long s, e;
        cin >> s >> e;
        long long l = s, r = e;
        if (s - 1 >= 0)
        {
            if (taken.find(s - 1) == taken.end())
            {
                l = s - 1;
            }
        }
        if (e + 1 <= x)
        {
            if (taken.find(e + 1) == taken.end())
            {
                r = e + 1;
            }
        }
        taken.insert(l);
        taken.insert(r);
        cout << (r - l + 1) * (l + r) / 2 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int getMaxHiddenChips(vector<int> imageDim, int k)
{
    int n = imageDim.size();

    if (n < 2)
    {
        return 0;
    }

    sort(imageDim.begin(), imageDim.end());

    int hiddenChipsCount = 0;
    int s_ptr = 0;
    int l_ptr = n / 2;

    while (s_ptr < n / 2 && l_ptr < n)
    {
        long long s_side = imageDim[s_ptr];
        long long l_side = imageDim[l_ptr];
        long long k_factor = k;

        if (l_side >= s_side * k_factor)
        {
            hiddenChipsCount++;
            s_ptr++;
            l_ptr++;
        }
        else
        {
            l_ptr++;
        }
    }

    return hiddenChipsCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> imageDim(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> imageDim[i];
    }

    int k;
    cin >> k;

    int result = getMaxHiddenChips(imageDim, k);

    cout << result << endl;

    return 0;
}

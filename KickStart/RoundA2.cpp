// Round-A 2021 L Shaped Slots
#include <bits/stdc++.h>
using namespace std;
int countL(int **matrix, int r, int c)
{
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; ++j)
        {
            if (matrix[i][j] == 0)
                continue;
            int H = 0, R = 0, L = 0, D = 0;
            int a = i;
            while (a >= 0 && matrix[a][j] == 1)
            {
                H++;
                a--;
            }
            a = i;
            while (a < r && matrix[a][j] == 1)
            {
                D++;
                a++;
            }
            int b = j;
            while (b >= 0 && matrix[i][b] == 1)
            {
                L++;
                b--;
            }
            b = j;
            while (b < c && matrix[i][b] == 1)
            {
                R++;
                b++;
            }
            int countTR = 0, countTL = 0, countDR = 0, countDL = 0;
            if (H >= 2 && R >= 2)
                countTR = min(H, R / 2) + min(R, H / 2) - 2;
            if (H >= 2 && L >= 2)
                countTL = min(H, L / 2) + min(L, H / 2) - 2;
            if (D >= 2 && R >= 2)
                countDR = min(D, R / 2) + min(R, D / 2) - 2;
            if (D >= 2 && L >= 2)
                countDL = min(D, L / 2) + min(L, D / 2) - 2;
            count += countTR + countTL + countDR + countDL;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int r, c;
        cin >> r >> c;
        int **matrix = new int *[r];
        vector<pair<int, int>> joint;
        for (int i = 0; i < r; ++i)
        {
            matrix[i] = new int[c];
            for (int j = 0; j < c; ++j)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == 1)
                {
                }
            }
        }
        int ans = countL(matrix, r, c);
        cout << "Case #" << i << ": " << ans << endl;
        // Delete
        for (int i = 0; i < r; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    return 0;
}
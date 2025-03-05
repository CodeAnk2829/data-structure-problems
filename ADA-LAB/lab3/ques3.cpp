// Write a program to check whether a given matrix is sparse matrix or not
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main()
{
    int m, n;
    cout << "Enter matrix rows and cols: ";
    cin >> m >> n;
    int mat[m][n];
    int cnt = 0;
    cout << "Enter matrix elements: " << endl;


    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 0)
                cnt++;
        }
    }
    if (cnt >= (m * n) / 2)
        cout << "Yes, the matrix is sparse\n";
    else
        cout << "No, the matrix is not sparse\n";
    

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    /*
    Time complexity of above program is O(m*n);
    and space complexity is O(1);
    Ofcourse Sparse matrix is better than the conventional
    matrix because
    it takes less space then the conventional matrix.
    */
    return 0;
}

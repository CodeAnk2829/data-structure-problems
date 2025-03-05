// Multiply two N x N matrices
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

int** multiplyMatrices(int** a, int** b, int n) {
    int** ans = new int*[n];
    for(int i = 0; i < n; ++i) {
        ans[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += a[i][j] * b[j][k];
            }
            ans[i][k] = sum;
        }
    }
    return ans;
}

int main()
{

    int n;
    cout << "Enter order of the two sqaure matrices" << endl;
    cin >> n;

    cout << "Enter elements in matrix A" << endl;
    int ** A = new int*[n];
    for(int i = 0; i < n; ++i) {
        A[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements in matrix B" << endl;
    int ** B = new int*[n];
    for(int i = 0; i < n; ++i) {
        B[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }
    // Get starting time point before function call
    auto start = high_resolution_clock::now();

    // Call the function
    int** ans = multiplyMatrices(A, B, n);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();


    cout << "Product of the two given matrices is: "  << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    
    // Delete
    for(int i = 0; i < n; ++i) {
        delete [] ans[i];
    }
    delete [] ans;
    
    return 0;
}

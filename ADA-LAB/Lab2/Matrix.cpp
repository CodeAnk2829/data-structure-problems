#include <bits/stdc++.h>
using namespace std;
void print(int** ans, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << ans[i][j] << " " ;
        }
        cout << endl;
    }
}

int** addMatrices(int** a, int** b, int n) {
    int** ans = new int*[n];
    for(int i = 0; i < n; ++i) {
        ans[i] = new int[n];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    return ans;
}

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

int** tranposeMatrix(int** a, int n) {
    int** ans = new int*[n];
    for(int i = 0; i < n; ++i) {
        ans[i] = new int[n];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans[i][j] = a[j][i];
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter order of matrices: ";
    cin >> n;
    int** a = new int*[n];
    int** b = new int*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new int[n];
        b[i] = new int[n];
    }
    // Take input
    cout << "Enter the entities of the matrix A" << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the entities of the matrix B" << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }
    cout << endl;

    // Addition of two matrices
    int** sum = addMatrices(a, b, n);
    cout << "Sum of matrices: " << endl;
    print(sum, n);
    cout << endl;
    
    // Multiplication of two matrices
    int** product = multiplyMatrices(a, b, n);
    cout << "Product of matrices: " << endl;
    print(product, n);
    cout << endl;

    // Transpose of a matrix
    int** transpose = tranposeMatrix(a, n);
    cout << "Transpose of matrix A: " << endl;
    print(transpose, n);
    cout << endl;

    // Delete matrices
    for(int i = 0; i < n; ++i) {
        delete [] a[i];
        delete [] b[i];
    }
    delete [] a;
    delete [] b;

    return 0;
}
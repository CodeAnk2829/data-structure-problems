/*
    Time Complexity: O(log(N)).
    Space Complexity: O(log(N)).

    Where 'N' is the given integer.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to multiply two matrices.
vector<vector<int>> multiply(vector<vector<int>> a,vector<vector<int>> b){

    const int mod = 1e9 + 7;
    
    // To store the resultant matrix.
    vector<vector<int>> c(2,vector<int>(2,0));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][k] = (c[i][k] + (long long)((long long)a[i][j] * (long long)b[j][k])) % mod;
            }
        }
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return c;
}

// Function to calclate n'th power of a matrix.
vector<vector<int>> matrix_power(vector<vector<int>> coef ,int n){

    // To store the resultant matrix.
    vector<vector<int>> res = {{1,0},{0,1}};

    // While loop till n > 0.
    while(n) {
        // If n is odd, multiply res with coef.
        if(n % 2) res = multiply(res,coef);

        // Multiply coef with coef and update n to n/2.
        coef = multiply(coef,coef);
        n /= 2;
    }

    return res;

}


int fibonacciNumber(int n){

    // Declaring the coef matrix.
    vector<vector<int>> coef={{1, 1},{1,0}};

    // Calculating the (n-1)th power of the coef matrix.
    vector<vector<int>> res = matrix_power(coef,n-1);

    // Return the bottom right element of the resultant matrix.
    return res[0][0];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacciNumber(n) << endl;
    return 0;
}
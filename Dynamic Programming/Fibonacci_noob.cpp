// Brute Force
// Time Complexity = O(2^n)
#include <bits/stdc++.h>
using namespace std;
int fibonaaci1(int n) {
    if(n <= 1) {
        return n;
    }
    int a = fibonaaci1(n - 1);
    int b = fibonaaci1(n - 2);

    return a + b;
}

int main() {
    int n; 
    cout << "Enter a number: "; 
    cin >> n;
    cout << fibonaaci1(n);
    return 0;
}
// Nth fibonacci number using Dynamic Progarmming Approach
// Time Comlexity = O(n)
// Space Complexity = O(1)
#include <iostream>
using namespace std;
int fibonacci(int n) {
    int a = 0, b = 1;
    int s;
    for(int i = 2; i <= n; ++i) {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}
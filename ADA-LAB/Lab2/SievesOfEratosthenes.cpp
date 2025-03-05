#include <bits/stdc++.h>
using namespace std;
vector<int> seivesOfEratosthenes(int n) {
    bool isPrime[n + 1];
    for(int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; ++i) {
        if(isPrime[i] == true) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        } 
    }
    vector<int> Prime;
    for(int i = 2; i <= n; ++i) {
        if(isPrime[i] == true) {
            Prime.push_back(i);
        }
    }
    return Prime;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> Prime = seivesOfEratosthenes(n);
    cout << "Prime numbers between 2 to " << n << endl;
    for(auto &p : Prime) {
        cout << p << " ";
    }
    return 0;
}
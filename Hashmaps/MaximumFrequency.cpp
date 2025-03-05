#include <iostream>
#include <unordered_map>
using namespace std;
int getMaximumFrequency(int* a, int size) {
    pair<int, int> p(a[0], 0);
    unordered_map<int, int> bucket;
    for(int i = 0; i < size; ++i) {
        bucket[a[i]]++;
        if(p.second < bucket[a[i]]) {
            p = {a[i], bucket[a[i]]};
        }
    }
    return p.first;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int result = getMaximumFrequency(a, n);
    cout << result << endl;
    return 0;
}
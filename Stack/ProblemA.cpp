#include <bits/stdc++.h>
using namespace std;
bool isBalanced(char *s) {
    stack <char> bucket;
    for(int i = 0; s[i]; ++i) {
        if(s[i] == 'Q') {
            bucket.push(s[i]);
        } else {
            if(bucket.empty() == false)
                bucket.pop();
        }
    }
    if(bucket.empty() == true) {
        return true;
    } 
    return false;
}
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int length;
        cin >> length;
        cin.ignore();
        char str[101];
        cin.getline(str, 101);
        if(isBalanced(str)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
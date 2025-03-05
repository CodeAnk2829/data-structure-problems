#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int n, vector<string>& s) {
    int size = s.size();
    string T;
    vector<string> result;

    for(int i = 0; i < size; i++) {
        vector<string> temp;
        stringstream X(s[i]);
        while(getline(X, T, '/')) {
            if(T[0] == 'r') {
                temp.push_back(T);
            }
        }
        string finalString = "";
        for(int j = 0; j < temp.size(); ++j) {
            if(temp.size() == 1) {
                finalString += temp[j];
            } else {
                if(j == 0) {
                    finalString += temp[j];
                } else {
                    finalString += "/" + temp[j];
                }
            }
        }
        result.push_back(finalString);
    }
    return result;
}

bool cmp(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    if(strcmp(a.c_str(), b.c_str()) > 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> s(n);
    for(auto &i : s) cin >> i;

    vector<string> result = solve(n, s);
    sort(result.begin(), result.end(), cmp);
    for(auto &i : result) cout << i << endl;
    return 0;
}
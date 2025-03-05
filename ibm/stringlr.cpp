#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<string>& s, vector<string>& q) {
    set<char> st = {'a' , 'e' , 'i' , 'o' , 'u'};
    vector<int> pf(s.size() + 1,0);
    for(int i = 0 ; i < s.size() ; i++){
        if(st.find(s[i].front()) != st.end() && st.find(s[i].back()) != st.end()){
            pf[i+1] = pf[i] + 1;
        }else pf[i+1] = pf[i];
    }

    vector<int> ans;
    for(int i = 0 ; i < q.size(); i++){
        stringstream str(q[i]);
        string sl;
        getline(str , sl , '-');
        int l = stoi(sl);
        getline(str,sl,'-');
        int r = stoi(sl);
        ans.push_back((pf[r] - pf[l-1]));
    }
    return ans;
}

int main(){
    
    vector<string> s={"yy","u","oe"};
    vector<string> q={"1-2","2-3"};
    
    vector<int> ans = solve(s, q);
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
}
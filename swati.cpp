#include <bits/stdc++.h>


using namespace std;

#define ll long long

map<string, string> m;

class Hash {
private:
    const ll MOD = 1e9 + 7;
    const ll BASE = 5689;
    vector<ll> hashes, basePowers;

public:
    Hash(string s) {
        ll n = s.size();
        hashes.assign(n + 1, 1);
        basePowers.assign(n + 1, 1);

        for(ll i = 0; i < n; ++i) {
            hashes[i + 1] = (hashes[i] * BASE + (s[i] - 'a' + 1)) % MOD;
            basePowers[i + 1] = (basePowers[i] * BASE) % MOD;
        }
    }

    ll getHash(ll l, ll r) {
        l++; r++;
        ll hash = (hashes[r] - (hashes[l - 1] * basePowers[r - l + 1]) % MOD + MOD) % MOD;
        return hash;
    }
};

string encode(vector<string> &strs)
{
    string encodedMsg = "";
    for(string &s : strs) {
        Hash h(s);
        ll hash = h.getHash(0, s.size() - 1);
        encodedMsg += to_string(hash);
        m[to_string(hash)] = s;
        encodedMsg.push_back(',');
    }
    return encodedMsg; 
}

vector<string> decode(string s) {
    vector<string> decodedMsg;
    char strChr[s.length() - 1];
    strcpy(strChr, s.c_str());
    char *token = strtok(strChr, ",");
    while(token != NULL) {
        string tokenAsString = token;
        decodedMsg.push_back(m[tokenAsString]);
        token = strtok(NULL, ",");
    }
    return decodedMsg;
}

int binPow(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}

int strToInt(string s)
{
    reverse(s.begin(), s.end());
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int n = int(s[i] - 48);
        num += (n * binPow(10, i));
    }
    return num;
}

int main()
{
    vector<vector<int>> a;
    a.push_back({1, 2});
    for(auto &i : a) {
        
    }
    return 0;
}
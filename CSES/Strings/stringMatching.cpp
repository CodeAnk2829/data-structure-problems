// https://cses.fi/problemset/task/1753/

// NOTE: Sometimes single hash works but sometimes where number
// of collisions would be more the answer would be wrong with some
// single hash hence we should try to take two hash values

#include <bits/stdc++.h>
using namespace std;

#define ll long long


class Hash {
private:
    const ll MOD = 1e9 + 7;
    const ll BASE1 = 5689;
    const ll BASE2 = 8861;
    vector<pair<ll, ll>> hashes, basePowers;

public:
    Hash(string s) {
        ll n = s.size();
        hashes.assign(n + 1, {1, 1});
        basePowers.assign(n + 1, {1, 1});

        for(ll i = 0; i < n; ++i) {
            ll textSubstringHashValue = (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD;
            ll patternHashValue = (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD;
            hashes[i + 1] = {textSubstringHashValue, patternHashValue};

            ll firstBasePower = (basePowers[i].first * BASE1) % MOD;
            ll secondBasePower = (basePowers[i].second * BASE2) % MOD;
            basePowers[i + 1] = {firstBasePower, secondBasePower};
        }
    }

    pair<ll, ll> getHash(ll l, ll r) {
        l++; r++;
        ll hash1 = (hashes[r].first - (hashes[l - 1].first * basePowers[r - l + 1].first) % MOD + MOD) % MOD;
        ll hash2 = (hashes[r].second - (hashes[l - 1].second * basePowers[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};

class SingleHash {
private:
    const ll MOD = 1e9 + 7;
    const ll BASE = 5689;
    vector<ll> hashes, basePowers;

public:
    SingleHash(string s) {
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

int main() {
    string text, pattern;
    cin >> text >> pattern;
    
    ll n = text.size();
    ll m = pattern.size();

    SingleHash s(text), t(pattern);
    ll count = 0;
    ll patternHash = t.getHash(0, pattern.size() - 1);

    for(ll i = 0; i + pattern.size() - 1 < text.size(); ++i) {
        ll textSubstringHash = s.getHash(i, i + pattern.size() - 1);

        if ((textSubstringHash == patternHash)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
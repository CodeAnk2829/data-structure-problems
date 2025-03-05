#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Hash {
private:
    const ll MOD = 1e9 + 7;
    const ll BASE1 = 5317;
    const ll BASE2 = 8819;

    // for calculating two hashes with two different bases and two mod
    // also precompute all the powers of the primes so as to access any power in O(1)
    vector<pair<ll, ll>> hashes, basePowers;

public:
    Hash(string s) {
        // one based indexing for hashes and basePowers
        hashes.assign(s.size() + 1, {0, 0});
        basePowers.assign(s.size() + 1, {1, 1});

        for(ll i = 0; i < s.size(); i++) {
            ll firstHashValue = (hashes[i].first * BASE1 + (s[i] - 'a' + 1)) % MOD;
            ll secondHashValue = (hashes[i].second * BASE2 + (s[i] - 'a' + 1)) % MOD;
            hashes[i + 1] = {firstHashValue, secondHashValue};

            ll firstBasePower = (basePowers[i].first * BASE1) % MOD;
            ll secondBasePower = (basePowers[i].second * BASE2) % MOD;
            basePowers[i + 1] = {firstBasePower, secondBasePower};
        }
    }

    // input is 0 based indexing
    // get hashes for a substring from l to r
    pair<ll, ll> getHashes(ll l, ll r) {
        l++; r++;
        // add MOD so that the stays positive
        ll hash1 = (hashes[r].first - (hashes[l - 1].first * basePowers[r - l + 1].first) % MOD + MOD) % MOD;
        ll hash2 = (hashes[r].second - (hashes[l - 1].second * basePowers[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll nextSmallerPrice(ll targetPrice, vector<ll>& ticketPrice, vector<bool>& alreadySold) {
    ll low = 0, high = ticketPrice.size() - 1;
    ll nextSmallerOrEqualPrice = -1;
    ll nextSmallerPriceFoundAt = -1;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(!alreadySold[mid] && ticketPrice[mid] == targetPrice) {
            nextSmallerOrEqualPrice = ticketPrice[mid];
            nextSmallerPriceFoundAt = mid;
            break;
        }
        if(ticketPrice[mid] <= targetPrice) {
            if(!alreadySold[mid]) {
                nextSmallerOrEqualPrice = ticketPrice[mid];
                nextSmallerPriceFoundAt = mid;
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(nextSmallerPriceFoundAt != -1) {
        alreadySold[nextSmallerPriceFoundAt] = true;
    }
    return nextSmallerOrEqualPrice;
}

vector<ll> priceAtWhichTicketsAreSold(ll n, ll m, vector<ll>& ticketPrice, vector<ll>& biddingPrice) {
    sort(ticketPrice.begin(), ticketPrice.end());
    vector<bool> alreadySold(n, false);
    vector<ll> result;

    for(int i = 0; i < m; i++) {
        ll nextSmaller = nextSmallerPrice(biddingPrice[i], ticketPrice, alreadySold);
        ll upperBoundIndex = upper_bound(ticketPrice.begin(), ticketPrice.end(), biddingPrice[i]) - ticketPrice.begin() - 1;
        if(upperBoundIndex > 0) {
            result.push_back(nextSmaller == -1 ? ticketPrice[upperBoundIndex]: -1);
        } else {
            result.push_back(-1);
        }

    }
    return result;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> ticketPrice(n);
    for(auto& t : ticketPrice) cin >> t;

    vector<ll> biddingPrice(m);
    for(auto& b : biddingPrice) cin >> b;

    vector<ll> result = priceAtWhichTicketsAreSold(n, m, ticketPrice, biddingPrice);
    for(auto& r : result) cout << r << endl;

    return 0;
}
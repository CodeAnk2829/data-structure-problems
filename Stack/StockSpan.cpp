// Stock Span Problem
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int>& stockPrices) {
    // contians the spans for each stock prices
    vector<int> span;
    stack<int> s;
    int n = stockPrices.size();
    for(int i = 0; i < n; ++i) {
        if(s.empty()) {
            span.push_back(i + 1);
        } else {
            // If we are not cosidering the equal prices in the span
            while(!s.empty() && stockPrices[s.top()] < stockPrices[i])  {
                s.pop();
            }

            // if we are considering the equal prices in the span as well
            /*
            while(!s.empty() && stockPrices[s.top()] <= stockPrices[i])  {
                s.pop();
            }
            */

           if(s.empty()) {
            span.push_back(i + 1);
           } else {
            span.push_back(i - s.top());
           }
        }
        s.push(i);
    }
    return span;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> prices;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            prices.push_back(x);
        }
        vector<int> span = stockSpan(prices);
        for(auto &x : span) {
            cout << x << " ";
        }
    }
    return 0;
}
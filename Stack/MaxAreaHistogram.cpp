// Maximum Area of Histogram
#include <bits/stdc++.h>
using namespace std;

// Find Next Smaller to Left
vector<int> findNSL(vector<int>& heights, int n) {
    vector<int> res;
    stack<int> s;
    // Traversal from left
    for(int i = 0; i < n; ++i) {
        if(s.empty()) {
            res.push_back(-1);
        } else {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if(s.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(s.top());
            }
        }
        s.push(i);
    }
    return res;
}

// Find Next Smaller to Right
vector<int> findNSR(vector<int>& heights, int n) {
    vector<int> res;
    stack<int> s;
    // Traversal from right
    for(int i = n - 1; i >= 0; --i) {
        if(s.empty()) {
            res.push_back(n);
        } else {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if(s.empty()) {
                res.push_back(n);
            } else {
                res.push_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int maxAreaOfHistogram(vector<int>& heights) {
    int size = heights.size();
    // Find next smaller to left from the left subarray
    vector<int> left = findNSL(heights, size);

    // Find next smaller to right from the right subarray
    vector<int> right = findNSR(heights, size);

    vector<int> width; // Stores width of the rectangle
    
    int maxArea = INT_MIN;
    for(int i = 0; i < size; ++i) {
        width.push_back(right[i] - left[i] - 1);
        int area = width[i] * heights[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> heights;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            heights.push_back(x);
        }
        int mah = maxAreaOfHistogram(heights);
        cout << mah << endl;
    }
    return 0;
}
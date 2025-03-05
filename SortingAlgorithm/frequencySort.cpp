#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> pi;

bool cmp(pi a, pi b) {
	if(a.second != b.second) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

vector<int> sortByFrequency(vector<int>& nums){
	map<int, int, greater<int>> freqOfElem;
	for(auto &elem : nums) {
		freqOfElem[elem]++;
	}
	
	vector<pi> temp;
	for(auto &frequentElem : freqOfElem) {
		temp.push_back({frequentElem.first, frequentElem.second});
	}
    
	sort(temp.begin(), temp.end(), cmp);

	vector<int> res;
	for(int i = 0; i < temp.size(); ++i) {
		for(int j = 0; j < temp[i].second; ++j) {
			res.push_back(temp[i].first);
		}
	}
	return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<int> c = sortByFrequency(v);
    for(auto &elem : c) {
        cout << elem << " ";
    }
    return 0;
}
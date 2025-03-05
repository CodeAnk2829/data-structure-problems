#include <bits/stdc++.h> 
using namespace std;
#include <bits/stdc++.h> 
int partition(vector<pair<int, int>>& arr, int lo, int hi) {
	int pivot = arr[hi].first;
	int pivotIndex = lo - 1;
	for(int i = lo; i < hi; ++i) {
		if(arr[i].first <= pivot) {
			swap(arr[i], arr[++pivotIndex]);
		}
	}
	swap(arr[++pivotIndex], arr[hi]);
	return pivotIndex;
}

int quickSelect(vector<pair<int, int>> &arr, int lo, int hi, int k) {
	if(k > 0 && k <= hi - lo + 1) {
		int pos = partition(arr, lo, hi);
		int count = pos - lo + 1;
		if(count == k) {
			return arr[pos].second;
		}
		if(count > k) {
			return quickSelect(arr, lo, pos - 1, k);
		}
		return quickSelect(arr, pos + 1, hi, k - count);
	}
	return INT_MAX;
}
vector<int> KClosest(vector<int> &a, int n, int k, int x) {
	vector<pair<int, int>> arr;
	for(auto &elem : a) {
		arr.push_back({abs(elem - x), elem});
	}
	quickSelect(arr, 0, n - 1, k);
	
	vector<int> res;
	for(int i = 0; i < k; ++i) {
		res.push_back(arr[i].second);
	}
	sort(res.begin(), res.end());
	return res;
}
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for(int i = 0; i < n ;++i) cin >> v[i];
    vector<int> res = KClosest(v, n, k, x);
    return 0;
}
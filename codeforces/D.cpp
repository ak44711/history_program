#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	int len;
	int x;
	int m1, m2;
	vector<int> arr;
	vector<int> res;
	for(int i = 0; i < t; i++) {
		cin >> len;
		arr.resize(len);
		for(int i = 0; i < len; i++) {
			cin >> x;
			arr[i] = x;
		}
		sort(arr.begin(), arr.end());
		int mid = arr.size() / 2;
		int m1 = upper_bound(arr.begin(), arr.end(), arr[mid]);
		int m2 = lower_bound(mid);
		res.push_back(m2 - m1);
	}
	for(int i = 0; i < res.size(); i++ {
		cout << res[i] << endl;
	}
	return 0;
}

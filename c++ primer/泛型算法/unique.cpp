#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

int main() {
	vector<int> v = {1,1,1,2,2,2};
	auto end_unique = unique(v.begin(), v.end());
	for(auto i : v) {
		cout << i	 << endl;
	}
	return 0;
}

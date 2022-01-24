#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	v.erase(find(v.begin(), v.end(), 11));
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	set<int> s = {10,11,12,13,14,15,16,17,18,19};
	auto res = find(s.begin(), s.end(), 5);
	if(res != s.end()){
		s.erase(res);
	}
	
	for(auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	} 
	cout << endl;
	return 0;
} 

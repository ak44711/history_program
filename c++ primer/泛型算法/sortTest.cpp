#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	vector<int> v;
	v = {2,0,0,1,3,5,2,3,3};
	sort(v.begin(), v.end(), cmp);
	for(auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

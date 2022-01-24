#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	vector<int> v;
	v = {1,2,3,4,5,6,7};
	fill(v.begin(), v.end(), 0);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	fill(v.begin(), v.begin() + 2, 1);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

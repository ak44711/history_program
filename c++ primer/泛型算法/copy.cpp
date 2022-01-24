#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	int size = sizeof(a1) / sizeof(*a1);
	vector<int> v(size);
	copy(begin(a1), end(a1), v.begin());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	vector<int> v = {1,8,2,0,0,1,3,5,2,3,3};
	sort(v.begin(), v.end(), [] (int a, int b){
		return a > b;
	});
	for(auto i : v) {
		cout << i << " ";
	}
	
	int t = 3;
	auto it = find_if(v.begin(), v.end(), [t](int a) {
		return a < t;
	});
	cout << endl <<  "it  " << *it << endl;
	cout << endl;
	
	int a = 1, b = 2;
	int temp;
	temp = [](int a, int b) {
		return a + b;
	};
	cout << temp << endl;
	return 0;
}

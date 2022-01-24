#include<numeric>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	int a = accumulate(v.begin(), v.end(), 0);
	cout << a << endl;
	
	string s = accumulate(v.cbegin(), v.cend(), string(""));
	cout << s << endl;
	return 0;
} 

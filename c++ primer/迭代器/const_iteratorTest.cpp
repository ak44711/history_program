#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	string s("7758258");
	vector<int>::iterator it1;
	string::iterator it2;
	vector<int>::const_iterator it3;
	string::const_iterator it4;
	
	for(it1 = v.begin(); it1 != v.end(); it1++){
		*it1 *= *it1;
		cout << *it1 << " ";
	}
	
	for(it3 = v.begin(); it3 != v.end(); it3++){
		// *it3 = 1; 错误 只能读，不能写 
		cout << *it3 << " ";
	}
	cout << endl;
	
	
	return 0;
}

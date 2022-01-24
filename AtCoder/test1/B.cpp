#include<iostream> 
using namespace std;
int main() {
	string N;
	cin >> N;
	int size = N.size();
	string t;
	if(size % 2 == 1) {
		size--;
		t.assign(size, '9');
	}else{
		t = N;
	}
	int len = size / 2;
	string s1 = t.substr(0, len);
	string s2 = t.substr(len, len);
	
	int res = atoi(s1.c_str());
	if(s1.compare(s2) > 0) {
		res--;
	}
	cout << res << endl;
	return 0;
}

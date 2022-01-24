#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int f(int n) {
	int res = 0;
	while(n) {
		res += pow(n % 10, 2);
		n /= 10;
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	set<int> s;
	while(n != 1) {
		s.insert(n);
		n = f(n);
		if(s.find(n) != s.end()) {
			break;
		}
 	}
 	if(n == 1) {
 		cout << "HAPPY" << endl; 
	 }else {
	 	cout << "UNHAPPY" << endl;
	 }
	return 0;
}

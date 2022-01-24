#include <iostream >
#include <vector >
#include <string>
#include<cstdlib>
#include<cmath> 
using namespace std;
string bigNumMul(string s1, string s2, int n) {
	if( n == 1 ){
		char buff[3];
		itoa(atoi(s2.c_str()) * atoi(s1.c_str()), buff, 10);
		string s(buff);
		return s;
	} 
	int halfN = n / 2;
	int t = pow(2,n);
	string A = s1.substr(0, halfN);
	string B = s1.substr(halfN, halfN);
	string C = s1.substr(0, halfN);
	string D = s1.substr(halfN, halfN);
	
	string one = bigNumMul(A, C, halfN);
	string two = bigNumMul(A, D, halfN);
	string three = bigNumMul(B, C, halfN);
	string four = bigNumMul(B, D, halfN);
}
int main( ) {
	string  s1;
	string s2;
	cin >> s1;
	cin >> s2; 
	cout << bigNumMul (s1, s2, 1) << endl;
	return 0;
}

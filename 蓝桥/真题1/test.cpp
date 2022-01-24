#include<string>
#include<iostream>
using namespace std;
int main() {
	string s = "2452454";
	int pos = s.find("9");
	string t = "32";
	s.find(t);
	cout << t.npos << endl;
	cout << pos << endl;
	
} 

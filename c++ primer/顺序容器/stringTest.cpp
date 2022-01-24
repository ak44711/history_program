//string vector<char> 
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	double pi = 3.14;
	string s= to_string(pi);
	cout << s << endl;
	
	string s1("100");
	int a = stoi(s1);
	cout << a;
}

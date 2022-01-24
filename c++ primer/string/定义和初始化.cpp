#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1;
	string s2 = s1;// = 是拷贝初始化 
	string s3 = "hiya";
	string s4(10,'c');//不带 = 是直接初始化 
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
} 


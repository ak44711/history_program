
#include<iostream>
#include<string>
using namespace std;
void error_msg(initializer_list<string> list) {
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

void error_msg1(string s1){
	cout << s1 << endl;
}
int main() {
	string s1 = "hello";
	string s2 = "world";
	error_msg1(s1);
	return 0;
} 
/*
13	17	C:\Users\hp\Desktop\基操\c++ prime\多行数组\initializer_list.cpp	[Error] could not convert 's1' from 'std::string {aka std::basic_string<char>}' to 'std::initializer_list<std::basic_string<char> >'
*/

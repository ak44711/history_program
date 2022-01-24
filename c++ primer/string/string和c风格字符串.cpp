#include<iostream> 
#include<string>

using namespace std;

int main(){
	string s;
	cin >> s;
	const char* str = s.c_str();
	printf("%s", str);
	cout << sizeof(s) << endl; 
	return 0;
}

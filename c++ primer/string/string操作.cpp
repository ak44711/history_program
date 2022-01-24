#include<iostream>
#include<string>

using namespace std;

int main(){
	/*多个string连写 
	string s1, s2;
	cin >> s1 >> s2; 
	cout << s1 << " " << s2 << endl;
	*/
	
	/*直到输入为 eof才停止输入 不计入空格 
	string word;
	while(cin >> word)
		cout << word << endl; 
	*/
	
	/*使用getline读取一行 
	string line;
	getline (cin, line);
	cout << line << endl;

	string line;
	while(getline(cin, line))
		cout << line << endl; 
	*/
	
	/*string.size() 计算s中不含'\0'的字符数 
	string s("sa");
	unsigned int a = s.size();
	cout << a << endl;
	*/
	
	/* string比较 
	string s1 = "Hello" ;
	string s2 = "Hello";
	string s3 = "Hiya";
	cout << (s1 > s3) << endl;
	cout << (s1 == s2) << endl;
	*/
	
	
	string s1 = "hello";
	string s2 = "world";
	string s3 = s1 + '4';
	string s4 = s1 + s2;
	//错误，不能两个字符串字面常量相加 
	string s5 = "hello" + "world"; 
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
} 

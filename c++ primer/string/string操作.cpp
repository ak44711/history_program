#include<iostream>
#include<string>

using namespace std;

int main(){
	/*���string��д 
	string s1, s2;
	cin >> s1 >> s2; 
	cout << s1 << " " << s2 << endl;
	*/
	
	/*ֱ������Ϊ eof��ֹͣ���� ������ո� 
	string word;
	while(cin >> word)
		cout << word << endl; 
	*/
	
	/*ʹ��getline��ȡһ�� 
	string line;
	getline (cin, line);
	cout << line << endl;

	string line;
	while(getline(cin, line))
		cout << line << endl; 
	*/
	
	/*string.size() ����s�в���'\0'���ַ��� 
	string s("sa");
	unsigned int a = s.size();
	cout << a << endl;
	*/
	
	/* string�Ƚ� 
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
	//���󣬲��������ַ������泣����� 
	string s5 = "hello" + "world"; 
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
} 

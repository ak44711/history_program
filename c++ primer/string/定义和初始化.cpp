#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1;
	string s2 = s1;// = �ǿ�����ʼ�� 
	string s3 = "hiya";
	string s4(10,'c');//���� = ��ֱ�ӳ�ʼ�� 
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
} 


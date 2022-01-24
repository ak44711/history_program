#include<iostream>
#include<string>

using namespace std;

bool lengthCompare(const string& s1, const string& s2){
	return s1 == s2;
}

int main(){
	bool (*pf)(const string&, const string&);
	pf = &lengthCompare;//pfָ����ΪlengthCompare�ĺ��� 
	pf = lengthCompare; //�ȼ۵ĸ�ֵ��䣺ȡ��ַ����ѡ�� 
	
	bool b1 = pf("hello", "goodbye");//b1�� b2�ȼ� 
	bool b2 = (*pf)("hello", "hello");
	bool b3 = lengthCompare("hello", "hello");
	
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	return 0;
}

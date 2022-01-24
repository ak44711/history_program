#include<iostream>
#include<string>

using namespace std;

bool lengthCompare(const string& s1, const string& s2){
	return s1 == s2;
}

int main(){
	bool (*pf)(const string&, const string&);
	pf = &lengthCompare;//pf指向名为lengthCompare的函数 
	pf = lengthCompare; //等价的赋值语句：取地址符可选的 
	
	bool b1 = pf("hello", "goodbye");//b1和 b2等价 
	bool b2 = (*pf)("hello", "hello");
	bool b3 = lengthCompare("hello", "hello");
	
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	return 0;
}

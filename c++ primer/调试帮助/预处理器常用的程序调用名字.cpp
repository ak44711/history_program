/*
__FILE__存放文件名的字符串字面值
__LINE__存放当前行号的整形字面值 
__TIME__存放文件编译时间的字符串字面值 
__DATE__ 存放文件编译日期的字符串字面值 
__func__当前函数的名字 
*/ 
#include<iostream>

//#define NDEBUG

using namespace std;

void print(const int ia[], size_t size)
{
//如果没有标注NDEBUG则将输出函数的名称 
#ifndef NDEBUG 
	cerr << __DATE__ << "-" << __TIME__ << endl; 
	cerr << __LINE__ << endl;
	cerr << __FILE__ << endl;
	cerr << __func__ << ":array size is" << size << endl;
#endif
}

int main(){
	cout <<  __func__ << endl;
	int a[10];
	//print(a, 5);
	return 0;
}

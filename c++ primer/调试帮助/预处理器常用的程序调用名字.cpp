/*
__FILE__����ļ������ַ�������ֵ
__LINE__��ŵ�ǰ�кŵ���������ֵ 
__TIME__����ļ�����ʱ����ַ�������ֵ 
__DATE__ ����ļ��������ڵ��ַ�������ֵ 
__func__��ǰ���������� 
*/ 
#include<iostream>

//#define NDEBUG

using namespace std;

void print(const int ia[], size_t size)
{
//���û�б�עNDEBUG��������������� 
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

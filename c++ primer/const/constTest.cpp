/*const 
*/ 
#include<iostream>

using namespace std;

int main(){
	int x = 3;
	int y = 5;
	//p1 �� p2�Ķ��巽ʽ��ȫ�ȼ� ָ��������Ըı䣬����ֻ�� 
	const int * p1 = &x;
	int const * p2 = &x;
	p1 = &y;
	
	//p4��p5���巽ʽ��ȫ�ȼ� ��ָ��ֵ�޷��ı䲢�ҽ����õ�ֵҲ�޷��ı� 
	const int * const p3 = &y;
	int const * const p4 = &y;
	
	//ָ��ֵ�޷��ı䣬���ǽ�����ֵ�޷��ı� 
	int * const p5 = &x;
	*p5 = 4;
	
	//����֮ǰ��const���������ֻ�� 
	const int &t = x;
	x = 10;
	// 	t = 20 �ᱨ�� 
	return 0;
}

#include<iostream>
#include<string>

using namespace std;

typedef string::size_type sz;
//��������Ĭ��ʵ�εĺ���  ��Ĭ�ϲ���ֵ�Ĳ�������������Ҷ�	
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' '); 

int main(){
	string window;
	window = screen();
	window = screen(66);
	window = screen(66, 256);
	window = screen(66, 256, '#');
	
	/*
	window = screen( , ,'?'); ����ֻ��ʡ��β����ʵ��
	window = screen('?') 	  ���� screen('?', 80, '#') 
	*/
	
	return 0;
}
//���庯��ʱ��ò�Ҫ��Ĭ�ϲ�������Ȼ�������������� 
string screen(sz ht, sz wid, char backgrnd){
	return " ";
} 

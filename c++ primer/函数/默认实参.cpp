#include<iostream>
#include<string>

using namespace std;

typedef string::size_type sz;
//声明含有默认实参的函数  有默认参数值的参数表必须在最右端	
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' '); 

int main(){
	string window;
	window = screen();
	window = screen(66);
	window = screen(66, 256);
	window = screen(66, 256, '#');
	
	/*
	window = screen( , ,'?'); 错误：只能省略尾部的实参
	window = screen('?') 	  调用 screen('?', 80, '#') 
	*/
	
	return 0;
}
//定义函数时最好不要加默认参数，不然过不过看编译器 
string screen(sz ht, sz wid, char backgrnd){
	return " ";
} 

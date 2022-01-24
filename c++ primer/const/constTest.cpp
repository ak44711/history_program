/*const 
*/ 
#include<iostream>

using namespace std;

int main(){
	int x = 3;
	int y = 5;
	//p1 和 p2的定义方式完全等价 指针变量可以改变，但是只读 
	const int * p1 = &x;
	int const * p2 = &x;
	p1 = &y;
	
	//p4和p5定义方式完全等价 其指针值无法改变并且解引用的值也无法改变 
	const int * const p3 = &y;
	int const * const p4 = &y;
	
	//指针值无法改变，但是解引用值无法改变 
	int * const p5 = &x;
	*p5 = 4;
	
	//引用之前加const，则此引用只读 
	const int &t = x;
	x = 10;
	// 	t = 20 会报错 
	return 0;
}

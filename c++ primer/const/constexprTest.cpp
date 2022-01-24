/*
constexpr函数通常和内联函数一样定义在头文件中 
*/ 
#include<iostream>

using namespace std;

constexpr int new_sz(){
	return 42;
}

/*constexpr函数不一定返回常量表达式，
当形参接受一个非常量表达式时，
返回值也是非常亮表达式 。 
*/ 
constexpr size_t scale(size_t cnt){
	return new_sz() * cnt;
}


int main(){
	constexpr int foo = new_sz();
	cout << foo << endl;
	constexpr int c1 = scale(2);
	int i = 2;
	//constexpr int c2 = scale(i); 错误 scale(i)不是常量表达式 
}

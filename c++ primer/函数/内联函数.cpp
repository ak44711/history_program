/*内联函数 
  内联编译是建议性的，有编译器决定的
  逻辑简单，调用频繁的函数用内联函数
  递归函数无法使用内联方式 
*/

#include<iostream> 
using namespace std;

inline void fun(int i = 30, int j = 20, int k = 10);


int main(){
	for(int i = 0; i < 1000000; i++){
		fun();
		fun(1);
		fun(1,2);
		fun(1,2,3);
	} 
	return 0;
}
void fun(int i, int j, int k){
	int t = i + j + k;
	int s = i + j;
	int p = i; 
}
/*编译时出错 
void fun(int i = 30, int j = 20, int k = 10){
	cout << i << " " << j << " " << k << endl;
}
*/

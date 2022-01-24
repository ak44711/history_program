#include<iostream>

using namespace std;

int main(){
	int ia[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9,10,11,12}
	};
	//ib 和 ia 等价 
	int  ib[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//显式的初始化每行的首元素 
	int ic[3][4] = { {0}, {4}, {8} };
	
	//指向 数组的引用 
	int (&row) [4] = ia[1];
	for(int i = 0; i < 4; i++) {
		cout << row[i] << " ";
	}
	cout << endl;
	
	size_t cnt = 0;
	for(auto &row : ia){
		//最内层的循环外，其他所有的控制变量都应该是引用变量 
		for(auto &col : row){
			cout << col << " " << " ";
		}
		cout << endl;
	}
	return 0;
}

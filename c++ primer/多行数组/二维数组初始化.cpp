#include<iostream>

using namespace std;

int main(){
	int ia[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9,10,11,12}
	};
	//ib �� ia �ȼ� 
	int  ib[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//��ʽ�ĳ�ʼ��ÿ�е���Ԫ�� 
	int ic[3][4] = { {0}, {4}, {8} };
	
	//ָ�� ��������� 
	int (&row) [4] = ia[1];
	for(int i = 0; i < 4; i++) {
		cout << row[i] << " ";
	}
	cout << endl;
	
	size_t cnt = 0;
	for(auto &row : ia){
		//���ڲ��ѭ���⣬�������еĿ��Ʊ�����Ӧ�������ñ��� 
		for(auto &col : row){
			cout << col << " " << " ";
		}
		cout << endl;
	}
	return 0;
}

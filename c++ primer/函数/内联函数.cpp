/*�������� 
  ���������ǽ����Եģ��б�����������
  �߼��򵥣�����Ƶ���ĺ�������������
  �ݹ麯���޷�ʹ��������ʽ 
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
/*����ʱ���� 
void fun(int i = 30, int j = 20, int k = 10){
	cout << i << " " << j << " " << k << endl;
}
*/

#include<iostream>
using namespace std;
int main() {
	int num[100] = {0};
	char ch[100] = {0};
	int idx1 = 0;
	int idx2 = 0;
	int n;
	char c;
	while(scanf("%d", &n)) {//输入第一个数字 
		c = getchar();//吃第一个符号或者空格 
		if(c == '\n' || n == 0) break;//输入了0 或者 回车 则结束
		num[idx1++] = n;
		//if(getchar() == '\n') break;//如果输入了回车就代表结束
		c = getchar();//吃符号 
		ch[idx2++] = c;//
		c = getchar();//吃空格 可加可以加， 因为下一个输入为数字，不会吃空格 
	}
	for(int i = 0; i < 100; i++) {
		printf("%d ", num[i]); 
	}
	printf("\n");
	for(int i = 0; i < 100; i++) {
		printf("%c ", ch[i]); 
	}
	printf("\n");
	return 0;
} 

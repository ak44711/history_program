#include<iostream>
using namespace std;
int main() {
	int num[100] = {0};
	char ch[100] = {0};
	int idx1 = 0;
	int idx2 = 0;
	int n;
	char c;
	while(scanf("%d", &n)) {//�����һ������ 
		c = getchar();//�Ե�һ�����Ż��߿ո� 
		if(c == '\n' || n == 0) break;//������0 ���� �س� �����
		num[idx1++] = n;
		//if(getchar() == '\n') break;//��������˻س��ʹ������
		c = getchar();//�Է��� 
		ch[idx2++] = c;//
		c = getchar();//�Կո� �ɼӿ��Լӣ� ��Ϊ��һ������Ϊ���֣�����Կո� 
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

#include<iostream>
#include<cctype>
#include<stdio.h>
#include<stack>
/*
Ŀ�꣺
1:����һ�У���������������ֺͿո� 
*/ 
using namespace std;
int main() {
	stack<double> num;
	int n, t;
	while(scanf("%d", &n)) {//��ÿ�е�һ������ 
		char c;
		c = getchar();//��ÿ�е�һ���ո���߻س� 
		if(c == '\n' && n == 0) break;//���һ��ֻ��һ��0 
		num.push(n);//n��ջ 
		c = getchar();//�Ե�һ���������
		double m;
		while(scanf("%d", &n)){//������������ 
			if(c == '*') {
				m = num.top();
				m = m * n;
				num.pop();
				num.push(m);
			}else if(c == '/'){
				m = num.top();
				m = m / n;
				num.pop();
				num.push(m);
			}else if(c == '-') {
				num.push(0 - m);
			}else if(c == '+') {
				num.push(n);
			}
			if(getchar() == '\n') break;//�Կո���߻س� 
			c = getchar();//�Է���
		}
		double sum = 0;
		while(!num.empty()) {
			sum += num.top();
			num.pop();
		}
		printf("%.2lf", sum);
	}
	return 0;
} 

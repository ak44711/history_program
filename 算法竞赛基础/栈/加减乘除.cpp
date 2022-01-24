#include<iostream>
#include<cctype>
#include<stdio.h>
#include<stack>
/*
目标：
1:输入一行，区分运算符、数字和空格 
*/ 
using namespace std;
int main() {
	stack<double> num;
	int n, t;
	while(scanf("%d", &n)) {//吃每行第一个数字 
		char c;
		c = getchar();//吃每行第一个空格或者回车 
		if(c == '\n' && n == 0) break;//如果一行只有一个0 
		num.push(n);//n入栈 
		c = getchar();//吃第一个运算符号
		double m;
		while(scanf("%d", &n)){//继续输入数字 
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
			if(getchar() == '\n') break;//吃空格或者回车 
			c = getchar();//吃符号
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

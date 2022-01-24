#include<iostream>
#define ElementType char
#define N 1e4 
using namespace std;

typedef struct stack{
	int top;
	int maxlen;
	ElementType data[N];
}stack;

void init(stack& stk, int maxlen){
	stk.maxlen = maxlen;
	stk.top = 0;
}

bool IsEmpty(stack& stk){
	return stk.top == 0;
}

bool IsFull(stack& stk) {
	return stk.maxlen == stk.top;
}

void Push(stack& stk, ElementType val) {
	if(!IsFull(stk)) stk.data[stk.top++] = val;
}

void Pop(stack& stk) {
	if(!IsEmpty(stk)) stk.top--;
}

ElementType Get(stack& stk) {
	if(!IsEmpty(stk)) {
		return stk.data[stk.top - 1];
	}
	return -1;
}
int main() {
	stack stk;
	init(stk, 20);
	string s;
	cin >> s;
	for(int i = 0; i < s; i++)
}

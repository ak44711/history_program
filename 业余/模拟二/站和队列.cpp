/*
循环链表 
设head指向第一个元素
tail指向最后一个元素的下一个元素。
我们用一个冗余位，即容量为n的队列只存放n-1个元素
判断队列满的条件时(tail + 1) % n == head 

共享栈
共享栈是两个栈共用一个线性表
两个栈的栈底分别占用线性表的两端
两个栈的生长方向是相向的
我们设一个栈的top1 起点是0， 另一个栈的起点是n-1 
我们用一个冗余位 即容量为n的共享栈只存放n-1个元素
则判断满的条件是 top1 == top2 
*/
int stack1[N], top1 = 0;
int stack2[N], top2 = 0;
int push(int x) {
	stack1[top1++] = x;
} 
int pop() {
	top1--;
}
int head() {
	top2 = 0;
	int t = top1;
	while(t--) {
		stack2[top2++] = stack1[t - 1];
	}
	return stack2[top2 - 1];
}
int tail() {
	return stack1[top1-1];
}

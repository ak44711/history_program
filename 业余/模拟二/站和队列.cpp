/*
ѭ������ 
��headָ���һ��Ԫ��
tailָ�����һ��Ԫ�ص���һ��Ԫ�ء�
������һ������λ��������Ϊn�Ķ���ֻ���n-1��Ԫ��
�ж϶�����������ʱ(tail + 1) % n == head 

����ջ
����ջ������ջ����һ�����Ա�
����ջ��ջ�׷ֱ�ռ�����Ա������
����ջ�����������������
������һ��ջ��top1 �����0�� ��һ��ջ�������n-1 
������һ������λ ������Ϊn�Ĺ���ջֻ���n-1��Ԫ��
���ж����������� top1 == top2 
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

/*
顺序表
	特点逻辑顺序就是物理顺序
	支持随机读取，读取效率高 
	插入或删除效率低，因为需要移动大量元素
链表：
	特点是逻辑顺序不一定是物理顺序。
	不支持随机读取，查找时要遍历链表
	插入或删除效率高 
*/
struct list{
	int val;
	struct list* next;
};  
int fac(int n) {
	int sum = 1;
	for(int i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}
int sum_fac(struct list* head) {
	int sum = 0;
	while(head) {
		sum += fac(head->val);
		head = head->next;
	}
	return sum;
} 

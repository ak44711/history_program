/*
˳���
	�ص��߼�˳���������˳��
	֧�������ȡ����ȡЧ�ʸ� 
	�����ɾ��Ч�ʵͣ���Ϊ��Ҫ�ƶ�����Ԫ��
����
	�ص����߼�˳��һ��������˳��
	��֧�������ȡ������ʱҪ��������
	�����ɾ��Ч�ʸ� 
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

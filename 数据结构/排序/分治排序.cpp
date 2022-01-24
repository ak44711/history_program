#include<iostream>
using namespace std;

const int N = 1e5 + 10;

/*�������򣨷ǽ��� 
**1.��һ����x��Ϊ����
**2.while(l < r) 
		���������ұ�x�����q[l]�����������ұ�xС����q[r]������q[l]��q[r]
**3.��ʱx��ߵ�����������x��x�ұߵ�����С��x�� ��x���� 
**4.��x��ߵ����е�����Ϊ������еݹ飬��y�ұߵ���Ϊ������еݹ� 
*/
void q_sort(int* q, int l, int r) {
	//���û��������ֻ��һ������������ 
	if(l >= r) return;
	//��Ϊ����ִ��i++, j--������������Ҫ��i++��j--֮���Ӧ�����ϵı߽硤 
	//ȡ�м����Ϊ����
	int x = q[(l + r + 1) / 2], i = l - 1, j = r + 1;
	while(i < j) {
		do i++; while(q[i] < x);
		do j--; while(q[j] > x);
		if(i < j) swap(q[i], q[j]);
	}
	q_sort(q, l, i - 1);
	q_sort(q, i, r);
	i = 0, j = 0;
}

/*�鲢����
**1.��������
**2.�����ұ߰�
**3.�ϲ�������������
**4.�ݹ��������Ԫ������һ��ʱ����Ҫ���� 
*/
int temp[N];//��������
void merge_sort(int *q, int l, int r) {
	if(l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while(i <= mid && j <= r) {
		if(q[i] < q[j]) {
			temp[k++] = q[i++];
		}else{
			temp[k++] = q[j++];
		}
	}
	while(i <= mid) temp[k++] = q[i++];
	while(j <= r) temp[k++] = q[j++];
	for(i = l, j = 0; i <= r; i++) {
		q[i] = temp[j++];
	}
} 

int main() {
	int q1[N], q2[N], n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &q1[i]);
		q2[i] = q1[i];
	}
	
    merge_sort(q1, 0, n - 1);//[0, n - 1] 
	q_sort(q2, 0, n - 1);
	
	for(int i = 0; i < n; i++)
		printf("%d ", q1[i]);
		
	printf("\n");
	
	for(int i = 0; i < n; i++)
		printf("%d ", q2[i]);
	return 0;
}

#include<iostream>
using namespace std;

const int N = 1e5 + 10;

/*快速排序（非降序） 
**1.找一个数x作为枢轴
**2.while(l < r) 
		从做往右找比x大的数q[l]，从右往左找比x小的数q[r]，交换q[l]和q[r]
**3.此时x左边的数都不大于x，x右边的数不小于x， 即x就绪 
**4.将x左边的所有的数作为数组进行递归，将y右边的作为数组进行递归 
*/
void q_sort(int* q, int l, int r) {
	//如果没有数或者只有一个数无需排序 
	if(l >= r) return;
	//因为是先执行i++, j--操作，所以需要在i++，j--之后对应到集合的边界· 
	//取中间的数为枢轴
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

/*归并排序
**1.排序左半边
**2.排序右边半
**3.合并两个有序数组
**4.递归基：数组元素少于一个时不需要排序 
*/
int temp[N];//辅助数组
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

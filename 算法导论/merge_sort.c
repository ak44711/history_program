#include<stdio.h>
#include<stdlib.h>

#define pos int
void merge(int A[], pos low, pos mid, pos high){
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int L[n1];
	int R[n2];
	int i = 0, j = 0;
	for(i = 0; i < n1; i++) {
		L[i] = A[low + i];
	}
	for(j = 0; j < n2; j++) {
		R[j] = A[mid + j + 1];
	}
	i = 0; j = 0;
	int k = low;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) A[k++] = L[i++];
	while(j < n2) A[k++] = R[j++];
}

void merge_sort(int A[], pos low, pos high) {
	if(low >= high) return; 
	pos mid = (high + low) / 2;
	merge_sort(A, low, mid);
	merge_sort(A, mid + 1, high);
	merge(A, low, mid, high);
	
}

int main() {
	int arr[] = {2,8,9,10,4,5,6,7};
	int size = sizeof(arr) / sizeof(*arr);
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
	merge_sort(arr, 0, size - 1);
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}

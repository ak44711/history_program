#include<iostream>

#define ElementType int

using namespace std;
/*
	2 4 5 6 1 3
	[2]4 5 6 1 3
	[2 4] 5 6 1 3
	[2 4 5] 6 1 3
	[2 4 5 6] 1 3
	[1 2 4 5 6] 3
	[1 2 3 4 5 6]
*/
void insertion_sort(ElementType A[], int size) {
	int i, j;
	int key;
	for(i = 1; i < size; i++) {
		key = A[i];
		//Insert A[i] into the sorted sequence A[1..j - 1].
		j = i - 1;
		while(j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
} 

int main() {
	int A[] = {2, 4, 5, 6, 1, 3};
	int size = sizeof(A) / sizeof(int);
	
	insertion_sort(A, size);
	
	for(int i = 0; i < size; i++){
		cout << A[i] << " " ;
	}
	cout << endl;
	return 0;
} 

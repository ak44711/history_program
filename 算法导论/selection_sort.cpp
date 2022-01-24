#include<iostream>

#define ElementType int

using namespace std;

/*
( [*]############# )
( [**]############ )
( [***]########### )
( [****]########## )
( [*****]######### )
( [******]######## )
( [*******]####### )
( [********]###### )
( [*********]##### )
( [**********]#### )
( [***********]### )
( [************]## )
( [*************]# )
( [**************] )
*/
void swap(ElementType* a, ElementType* b){
	ElementType temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(ElementType A[], int size){
	int min;
	for(int i = 0; i < size - 1; i++){
		min = i;
		for(int j = i; j < size; j++){
			if(A[j] < A[min]){
				min = j;
			}
		}
		swap(&A[i], &A[min]);
	}
}

int main() {
	int A[] = {5, 2, 4, 6, 1, 3};
	int size = sizeof(A) / sizeof(int);
	
	selection_sort(A, size);
	
	for(int i = 0; i < size; i++){
		cout << A[i] << " " ;
	}
	cout << endl;
	
	return 0;
}

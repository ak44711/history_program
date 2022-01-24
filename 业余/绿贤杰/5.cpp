#include<stdio.h>
void mod_3(int a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d mod 3 = %d\n", i, i % 3);
	}
}
int main() {
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(a[0]);
	mod_3(a, n);
	return 0;
}

#include<stdio.h>
int min_3(int a, int b, int c) {
	a = a < b ? a : b;
	return a < c ? a : c;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("min_3 -- %d\n", min_3(a, b, c));
	
	printf("min -- %d\n", min(a, b) < c ? min(a, b) : c);
} 

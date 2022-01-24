#include<stdio.h>
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int main() {
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	if(n1 > n2) {
		swap(&n1, &n2);
	}
	int i;
	int ans = 0;
	int t1, t2;
	int flag = 0;
	for(i = n1; i <= n2; i++) {
		t1 = (i / 10) % 10;//十位 
		t2 = i % 10;//个位
		if(t1 == t2 && i % 3 == 0) {
			flag = 1;
			ans = i;
		} 
	}
	if(flag == 1) {
		printf("%d", ans);
	}else {
		printf("没有");
	}
} 

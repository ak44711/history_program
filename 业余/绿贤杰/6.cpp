#include<stdio.h>

void encrypt(char a[]) {
	char table[] = "CaqXihbMSr";
	int i = 0;
	while(a[i]) {
		a[i] = table[a[i] - '0'];
		i++;
	}
}
int main()  {
	char a[] = "0123456";
	printf("%s\n", a);
	encrypt(a);
	printf("%s\n", a);
	return 0;
}	

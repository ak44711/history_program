#include<stdio.h>

int int_digit(int num) {
	int i = 0;
	do {
		i++;
		num /= 10;
	}while(num > 0);
	return i;
}
int main() {
	int x = 4444;
	printf("%d\n", int_digit(x));
}

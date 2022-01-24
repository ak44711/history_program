#include<iostream>
using namespace std;
int main() {
	//int a, b, c;
	//printf("%d\n", scanf("%d%d%d", &a, &b, &c));
	//printf("~0 %d\n", ~0);
	//printf("~1 %d\n", ~(-1));
	char arr[5][5];
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			arr[i][j] = '*';
		}
	}
	char c;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(j==2 && i == 2) {
				scanf("%c", &c);
			}else{
				scanf("%c ", &c);
			}
			arr[i][j] = c;
		}
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
} 

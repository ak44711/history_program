#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[21], n;
int arr2[21];
bool used[21];
int stk[21];

void dfs(int depth) {
	if(depth == n) {
		for(int i = 0; i < n; i++) {
			printf("%d ", stk[i]);
		}
		printf("\n");
	}
	for(int i = 0; i < n; i++) {
		if(used[i] == false) {
			used[i] = true;
			stk[depth] = arr[i];
			dfs(depth + 1);
			used[i] = false;
		}
	}
}
void permutation() {
	do{
		for(int i = 0; i < n; i++) {
			printf("%d ", arr2[i]);
		}
		printf("\n");
	}while(next_permutation(arr2,  arr2 + n));
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		arr[i] = i;
		arr2[i] = i;
		used[i] = false;
	}
	printf("dfs\n");
	dfs(0);
	printf("permutation\n");
	permutation();
	return 0;
} 

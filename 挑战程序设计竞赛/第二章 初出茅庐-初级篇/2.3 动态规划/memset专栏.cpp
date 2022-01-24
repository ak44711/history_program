#include<cstring>
#include<cstdio>
using namespace std; 
const int maxn = 10;
int A[maxn];
int main() {
	memset(A, -1, sizeof(A));
	for(int i = 0; i < maxn; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}

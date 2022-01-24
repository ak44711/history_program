#include<cstdio>
#include<cstring>
/*
如果一个数字是素数， 则其倍数一定不是素数 
事件复杂度 nlogn 
*/
using namespace std;
const int maxn = 1e8;
bool prime[maxn];
int p[maxn];
int main() {
	memset(prime, 0, sizeof(prime));
	int n;
	scanf("%d", &n);
	int tot = 0;
	for(int i = 2; i <= n; i++) {
		if(prime[i] == 0) {
			p[++tot] = i;
			for(int j = 2; j * i <= n; j++) {
				prime[i * j] = 1;
			}
		}
	}
	for(int i = 1; i <= tot; i++) {
		printf("%d ", p[i]);
	}
	return 0;
} 

#include<cstdio>
#include<cstring>
/*
每个合数仅用其最小素数Pmin和t表示 
事件复杂度 nlogn 
*/
typedef long long ll;
const ll maxn = 1e6 + 10;

bool isPrime[maxn];
int prime[maxn];
int cnt = 0;

int main() {
	int step = 0;
	memset(isPrime, 0, sizeof(isPrime));
	int n = 500;
	isPrime[0] = 1;
	isPrime[1] = 1;
	for(int i = 2; i <= n; i++) {
		/**/printf("%d -- ", i);
		if(isPrime[i] == 0) {//如果一个数没有被标记为非素数，则判定为素数，加入素数数组 
			prime[cnt++] = i;
		}
		/**/printf("\t%d ", isPrime[i]);
		for(int j = 0; j < cnt && prime[j] * i <= n; j++) {//将其倍数标记位非素数
			step++;
			isPrime[i * prime[j]] = 1;//标记为非素数
			/**/printf("%d ", i * prime[j]);
			if(i % prime[j] == 0) break;//如果i是prime[j]的最小因子，，停止标记
		}
		/**/printf("\n");
	}
	printf("%d", step);
	return 0;
} 

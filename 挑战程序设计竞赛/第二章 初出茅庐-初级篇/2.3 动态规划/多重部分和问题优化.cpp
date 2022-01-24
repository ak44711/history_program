#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
const int maxk = 1e5 + 10;
int a[maxn];
int m[maxn];
int n;
int K;
int dp[maxn][maxk];
/*dp[i][j] : = 用前i种数加和加到j时第i种数最多能剩余多少个（不能加和加到j的情况为-1） 
*/
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		scanf("%d", &m[i]);
	}
	scanf("%d", &K);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= K; j++) {
			if(dp[i][j] >= 0) {
				dp[i + 1][j] = m[i];
			}else if(j < a[i] || dp[i + 1][j - a[i]] <= 0) {
				dp[i + 1][j] = -1;
			}else {
				dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
			}
		}
	}
	if(dp[n][K] >= 0) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
	return 0;
} 

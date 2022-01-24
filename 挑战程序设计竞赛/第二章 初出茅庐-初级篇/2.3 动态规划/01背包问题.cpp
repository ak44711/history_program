#include<cstdio>
#include<iostream> 
using namespace std;
const int maxn = 102;
const int maxw = 10010;
int v[maxn], w[maxn];
int dp[maxn][maxw];
int n, W;
int main() {
	scanf("%d%d", &n, &W);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(int i = 0; i < n; i++) 	dp[i][0] = 0;
	for(int i = 0; i < W; i++) dp[0][i] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= W; j++) {
			if(j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	printf("%d\n", dp[n][W]);
	return 0;
}
/* 
4 5 
2 1 3 2
3 2 4 2

*/

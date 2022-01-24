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
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= W; j++) {
			if(j < w[i]) {
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d", dp[n][W]);
}
/* 
3 7 
3 4 2
4 5 3

*/

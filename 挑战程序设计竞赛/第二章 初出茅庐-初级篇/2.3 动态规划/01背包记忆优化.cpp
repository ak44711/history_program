#include<cstring>
#include<cstdio>
using namespace std; 
const int maxn = 10010;
int dp[maxn][maxn];
int v[maxn], w[maxn];
int n, W;
int max(int a, int b) {
	return a > b ? a : b;
}
int rec(int i, int j) {
	if(dp[i][j] >= 0) {
		return dp[i][j];
	}
	int res;
	if(i == n) {
		res = 0;
	} else if (j < w[i]) {
		res = rec(i + 1, j);
	} else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}
int main() {
	scanf("%d%d", &n, &W);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0,W));
	return 0;
} 

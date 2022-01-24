#include<cstdio>
#include<iostream> 
#include<algorithm>
using namespace std;
const int maxn = 102;
const int maxw = 1e7 + 10;
const int maxv = 102;
const int INF = INT_MAX / 2;

int v[maxn], w[maxn];
int dp[maxn][maxn * maxv];
int n, W;
int main() {
	/*
	scanf("%d%d", &n, &W);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	*/
	fill(dp[0], dp[0] + maxn * maxv + 1, INF);
	for(int i = 0; i < 10; i++) {
		printf("%d ", dp[0][i]);
	}
}

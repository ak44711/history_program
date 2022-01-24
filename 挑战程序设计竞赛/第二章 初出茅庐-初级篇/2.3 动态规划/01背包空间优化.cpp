#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 102;
const int maxw = 10010;
int v[maxn], w[maxn];
int dp[maxn] = {0};
int n, W;
int main() {
	scanf("%d%d", &n, &W);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = W; j >= 0; j--) {
			if(j >= w[i]) {
				dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
			}
		}
	}
	printf("%d\n", dp[W]);
	return 0;
}
/* 
4 5 
2 1 3 2
3 2 4 2
*/

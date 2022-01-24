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
bool dp[maxn][maxk];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		scanf("%d", &m[i]);
	}
	scanf("%d", &K);
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= K; j++) {
			for(int k = 0; k <= m[i] && k * a[i]  <= j; k++) {
				if(dp[i][j - k * a[i]] == true) {
					dp[i + 1][j] = true;
				}
			}
		}
	}
	if(dp[n][K] == true) {
		printf("yes\n");
	}else {
		printf("no\n");
	}
 	return 0;
} 
/*
3
3 3
5 2
8 2
17
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1010;
const int maxa = 1e6 + 10;
int a[maxn];
int n;
int dp[maxa] ={0};//以a[i]为末尾的最长上升子序列的长度 
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j <= i; j++) {
			if(a[i] > a[j]) 
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}
/*
5
4 2 3 1 5
*/

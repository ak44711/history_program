#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std; 
const int maxn = 1010;
int dp[maxn][maxn];
string s, t;
int n, m;
int main() {
	cin >> n >> m;
	cin >> s >> t;
	for(int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}
	for(int i = 0; i < m; i++) {
		dp[0][i] = 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
/*
4 4
abcd
becd
*/

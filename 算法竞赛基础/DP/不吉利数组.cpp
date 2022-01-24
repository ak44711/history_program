#include<iostream>
using namespace std;
typedef long long ll; 
ll dp[30][3];
/*
dp[i][0]：吉利数字
dp[i][1]：吉利数字并且结尾是6
dp[i][2]: 不吉利的数字
*/
void Init() {
	dp[1][0] = 9;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	for(int i = 2; i < 30; i++) {
		dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];//结尾不能加4，并且前一个结尾为6不能加2
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][0] + dp[i - 1][1];
	}
	for(int i = 0; i <= 20; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%lld\t", dp[i][j]);
		}
		printf("\n");
	}
}
int getCnt(ll n) {
	int t = n; 
	int a[22] = {0};
	int i = 0;
	while(n > 0) {
		a[++i] = n % 10;
		n /= 10;
	}
	ll ans = 0;
	bool flag = false;
	for(; i > 0; i--) {
		ans += dp[i-1][2]*a[i];//
		if(flag) ans += dp[i-1][0]*a[i];//如果高位出现了不吉利数，则低位随便都行，因为上一行代码已经加上了i-1位包含不吉利数字的情况，所以这里加上不包含不吉利数字的情况 
		else if(a[i] > 6) ans += dp[i - 1][1];
		if(a[i + 1] == 4 || a[i] == 2 && a[i + 1] == 6) flag = true;
	}
	return t - ans;
}
int main() {
	Init();
	int a, b;
	cin >> a >> b;
	cout << getCnt(b + 1) - getCnt(a) << endl;
	return 0;
} 

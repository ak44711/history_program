#include<cstdio>
#include<cstring>
using namespace std;
void solution() {
	int ans = 0;
	for(int i = 1; i <= 2020; i++) {
		int t = i;
		while(t > 0) {
			if(t % 10 == 2) {
				ans++;
			}
			t /= 10;
		}
	}
	printf("%d\n", ans);
}
int dp[2030];
int main() {
	memset(dp, 0, sizeof(dp));
	dp[2] = 1;
	int ans = 1;
	for(int i = 10; i <= 2020; i++) {
		dp[i] = (int)(i % 10 == 2) + dp[i / 10];
		ans += dp[i];
	}
	printf("%d-\n", ans);
	solution();
	return 0;
} 

#include<iostream>
#include<cstring>
#define MAX 22
using namespace std;
typedef long long ll;
ll dp[MAX][3];
ll a[MAX + 1];
/*
	定义	递推公式
dp[i][0]	前i位不含49的数的个数					dp[i][0]=dp[i-1][0]*10-dp[i-1][1]
dp[i][1]	前i位不含49的数的个数且第i位为4的个数	dp[i][1]=dp[i-1][0]
dp[i][2]	前i为含49的数的个数						dp[i][2]=dp[i-1][2]*10+dp[i-1][1]

*/
void Init() {//初始化dp表格 
	dp[1][0] = 10;
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[0][0]=1;
	for(int i = 2; i < MAX; i++) {
		dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1]; 
	}
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}
}
int main() {
	Init();
	int T;
	cin >> T;//T组数据 
	while(T--){
		ll n; 
		cin >> n;//炸弹设置的数 
		n++;//防止末尾是49的情况 
		int i = 0;
		memset(a, 0, sizeof(a));//a数组全部置0 
		while(n != 0) {//把n倒序存进数组a 
			a[++i] = n % 10;
			n /= 10;
		}
		ll ans = 0;//结果 
		bool flag = false;//是否出现49
		for(i=i; i > 0; i--) {
			/*501
			=5 * dp[2][2] + dp[2][1]+
			01
			+0 * dp[1][2]
			1
			+dp[1][2] 
			*/
			ans += a[i] * dp[i-1][2];
			if(flag) ans += dp[i-1][0] * a[i];//如果高位出现了49，低位可以随便组合，因为上面已经加了包含49的个数，所以只需要加上不包含49的个数 
			else if(a[i] > 4) ans += dp[i-1][1];//最高位大于4，会有4、9组合,不覆盖包含4是因为下面的if语句单独判断过了 
			if(a[i+1] == 4 && a[i]==9)flag = true;//出现了49需要标记
		}
		cout << ans << endl;
	}
	return 0;
} 

#include<iostream>
using namespace std;
typedef long long ll; 
ll dp[30][3];
/*
dp[i][0]����������
dp[i][1]���������ֲ��ҽ�β��6
dp[i][2]: ������������
*/
void Init() {
	dp[1][0] = 9;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	for(int i = 2; i < 30; i++) {
		dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];//��β���ܼ�4������ǰһ����βΪ6���ܼ�2
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
		if(flag) ans += dp[i-1][0]*a[i];//�����λ�����˲������������λ��㶼�У���Ϊ��һ�д����Ѿ�������i-1λ�������������ֵ����������������ϲ��������������ֵ���� 
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

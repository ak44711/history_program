#include<iostream>
#include<cstring>
#define MAX 22
using namespace std;
typedef long long ll;
ll dp[MAX][3];
ll a[MAX + 1];
/*
	����	���ƹ�ʽ
dp[i][0]	ǰiλ����49�����ĸ���					dp[i][0]=dp[i-1][0]*10-dp[i-1][1]
dp[i][1]	ǰiλ����49�����ĸ����ҵ�iλΪ4�ĸ���	dp[i][1]=dp[i-1][0]
dp[i][2]	ǰiΪ��49�����ĸ���						dp[i][2]=dp[i-1][2]*10+dp[i-1][1]

*/
void Init() {//��ʼ��dp��� 
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
	cin >> T;//T������ 
	while(T--){
		ll n; 
		cin >> n;//ը�����õ��� 
		n++;//��ֹĩβ��49����� 
		int i = 0;
		memset(a, 0, sizeof(a));//a����ȫ����0 
		while(n != 0) {//��n����������a 
			a[++i] = n % 10;
			n /= 10;
		}
		ll ans = 0;//��� 
		bool flag = false;//�Ƿ����49
		for(i=i; i > 0; i--) {
			/*501
			=5 * dp[2][2] + dp[2][1]+
			01
			+0 * dp[1][2]
			1
			+dp[1][2] 
			*/
			ans += a[i] * dp[i-1][2];
			if(flag) ans += dp[i-1][0] * a[i];//�����λ������49����λ���������ϣ���Ϊ�����Ѿ����˰���49�ĸ���������ֻ��Ҫ���ϲ�����49�ĸ��� 
			else if(a[i] > 4) ans += dp[i-1][1];//���λ����4������4��9���,�����ǰ���4����Ϊ�����if��䵥���жϹ��� 
			if(a[i+1] == 4 && a[i]==9)flag = true;//������49��Ҫ���
		}
		cout << ans << endl;
	}
	return 0;
} 

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int k, l;
	cin >> k >> l;
	vector<vector<long long> > dp(l, vector<long long> (k));
	for(int i = 0; i < k; i++) {
		dp[0][i] = 1;
	}
	for(int i = 1; i < l; i++) {
		for(int j = 0; j < k; j++) {
			for(int m = 0; m < k; m++) {
				if(m != j + 1 && m != j - 1) {
					dp[i][j] += dp[i - 1][m];
					dp[i][j] %= 1000000007;
				}		
			}
		}
	}
	long long res = 0;
	for(int i = 1; i < k; i++) {
		res += dp[l - 1][i];
		res %= 1000000007;
	}
	cout << res << endl;
	return 0;
}

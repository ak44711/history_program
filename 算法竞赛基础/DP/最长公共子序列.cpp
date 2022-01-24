#include<iostream>
#include<string>
using namespace std;

int lcs(string s1, string s2) {
	int row = s1.size() + 1;
	int col = s2.size() + 1;
	int dp[row][col];
	for(int i = 0; i < row; i++) {
		dp[i][0] = 0;
	}
	for(int j = 0; j < col; j++) {
		dp[0][j] = 0;
	}
	for(int i = 1; i < row; i++){
		for(int j = 1; j < col; j++) {
			if(s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	return dp[row - 1][col - 1];
	
}
int lcs(string s1, string s2, int len1, int len2) {
	if(len1 == 0 || len2 == 0) {
		return 0;
	}
	if(s1[len1 - 1] == s2[len2 - 1]) {
		return lcs(s1, s2, len1 - 1, len2 - 1) + 1;
	}
	return max(lcs(s1, s2, len1, len2 - 1), lcs(s1, s2, len1 - 1, len2));
}

int  main() {
	string s1 = "ABCB";
	string s2 = "BDCABA";
	cout << lcs(s1, s2) << endl;
	return 0;
}

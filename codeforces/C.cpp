#include<iostream>
#include<string>
#include<vector>
using namespace std;

int f(string& s1, string& s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	int arr[len1 + 1][len2 + 1];
	for(int i = 0; i <= len1; i++) {
		arr[i][0] = 0;
	}
	for(int j = 0; j < len2; j++) {
		arr[0][j] = 0;
	}
	int maxlen = 0;
	for(int i = 1; i <= len1; i++) {
		for(int j = 1; j <= len2; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				maxlen = max(maxlen, arr[i][j]);
			}else{
				arr[i][j] = 0;
			}
		}
	}
	return maxlen;
} 

int main() {
	int t;
	cin >> t;
	string s1, s2;
	vector<int> res(t);
	for(int i = 0; i < t; i++) {
		cin >> s1 >> s2;
		res[i] = s1.size() + s2.size() - 2 * f(s1, s2);
	}
	for(int i = 0; i < t; i++) {
		cout << res[i] << endl;
	}
	return 0;
}

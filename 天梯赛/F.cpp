#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
bool f(string s, string s2) {
	bool flag;
	for(int i = 0; i < s.size() - s2.size(); i++) {
		flag = true;
		for(int j = 0; j < s2.size(); j++) {
			if(s[i + j] != s2[j]) {
				flag = false;
			}
		}
		if(flag) return true;
	}
	return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	string s = "123456789";
	int idx = -1;
	string ans = "Wo AK le";
	cin.get();
	for(int i = 0; i < N; i++) {
		getline(cin, s);
		if(f(s, "easy") || f(s, "qiandao"));
		else{
			idx++;
			if(idx == M) ans = s;
		}
	}
	cout << ans << endl;
	
	
	return 0;
}

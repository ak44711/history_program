#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
int main() {
	int n;
	cin >> n;
	string passwd;
	vector<string> passwds(n);
	for(int i = 0; i < n; i++) {
		getline(cin, passwds[i]);
	}
	bool hasNum, hasAlpha, illegalCh;
	int len;
	for(int i = 0; i < n; i++) {
		len = passwds[i].size();
		hasNum = false;
		hasAlpha = false;
		illegalCh = false;
		for(int j = 0; j < len; j++) {
			if(isalpha(passwds[i][j])){
				hasAlpha = true;
			}else if(isdigit(passwds[i][j])){
				hasNum = true;
			}else if(passwds[i][j] == '.'){
			}else{
				illegalCh = true;
			}
		}
		if(len < 6){
			cout << "Your password is tai duan le." << endl;
		}else if(illegalCh){
			cout << "Your password is tai luan le." << endl;
		}else if(!hasAlpha && hasNum){
			cout << "Your password needs zi mu." << endl;
		}else if(!hasNum && hasAlpha) {
			cout << "Your password needs shu zi." << endl;
		}else{
			cout << "Your password is wan mei."  << endl;
		}
	}
	return 0;
}

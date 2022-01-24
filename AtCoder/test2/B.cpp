#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int i = 0, j = s.size() - 1;
	bool flag = false;
	while(s[j] == '0') j--;
	while(i <= j) {
		if(s[i] != s[j]) {
			flag = true;
			break;
		}
		i++;
		j--;
	}
	if(!flag)
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	return 0;
}

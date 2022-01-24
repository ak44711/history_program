#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool isPrime(string s) {
	int n = 0;
	for(unsigned int i = 0; i < s.size(); i++) {
		n = n * 10 + s[i] - '0';
	}
	int sqrtn = sqrt(n);
	for(int i = 2; i <= sqrtn; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int len, k;
	cin >> len >> k;
	string s;
	cin >> s;
	int i = 0;
	int j = k;
	while(j <= len) {
		if(isPrime(s.substr(i, j - i))){
			cout << s.substr(i, j - i) << endl;
			break;
		}
		i++;
		j++;
	}
	if(j > len) {
		cout << "404" << endl;
	}
	return 0;
	
}

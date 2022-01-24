#include<iostream>
#include<cmath>
using namespace std;

int f(int n) {
	int k = 0;
	while(n > 1) {
		for(int j = 0; j < n; j++) {
			k ++;
		}
		n /= 2;
	}
	return k;
}

int main() {
	int t; 
	cout << "ÇëÊäÈët:" << endl;
	cin >> t;
	int n = pow(2, t);
	cout << f(n) << endl;
	return 0;
}

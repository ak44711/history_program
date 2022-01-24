#include<iostream>
using namespace std;

int count(int n) {
	int k = 0; 
	int m;
	for(int i = 1; i <= n; i++) {
		m = n / i;
		for(int j = 1; j <= m; j++){
			k ++;
		}
	}
	return k;
}

int main() {
	int n;
	cout << "ÇëÊäÈën" <<endl;
	cin >> n;
	cout << count(n) << endl;
	return 0;
}

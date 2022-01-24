#include<iostream>
using namespace std;
int gcd(int a, int b) {
	int t = a % b;
	if(t == 0) return b;
	return gcd(b,t);
}
int lcm(int a, int b) {
	return a * b / gcd(a,b);
}
int main() {
	int a, b;
	cin >> a >> b;
	int x = lcm(a,b);
	int ans = -1;
	bool flag = false;
	for(int i = 1; i <= x; i++) {
		flag = false;
		for(int j = 0; j < i / a + 1; j++) {
			if((i - a * j) % b == 0) {
				flag = true;
				break;
			}
		}
		if(flag == false) ans = max(ans, i);
	}
	cout << ans << endl;
	return 0;
} 

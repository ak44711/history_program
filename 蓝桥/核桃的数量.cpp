#include<iostream> 
#include<vector>
using namespace std;

int gcd(int a, int b) {
	if(a % b == 0) return b;
	if(a < b) swap(a, b);
	return gcd(a % b, b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << lcm(lcm(a,b), c) << endl;
	return 0;
} 

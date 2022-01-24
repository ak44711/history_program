#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	ll t = a % b;
	if(t == 0) {
		return b;
	}
	return gcd(b, t);
}
int main() {
	ll m, n;
	cin >> m >> n;
	ll t = gcd(m,n);
	m /= t;
	n /= t;
	if(m % 2 == 1 && n % 2 == 1){
		cout << gcd(m,n)<< endl;
	}else{
		cout << 0 << endl; 
	}
	return 0;
}	

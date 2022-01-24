#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int t;
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++) {
		cin >> t;
		if(t % 2 == 0) {
			even++;
		}else{
			odd++;
		}
	}
	cout << odd << " " << even << endl;
	return 0;
}

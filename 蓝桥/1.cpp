#include<iostream>
using namespace std;
int num[10];
bool comp(int n) {
	while(n > 0) {
		int t = n % 10;
		if(num[t] == 0) return false;
		else num[t]--;
		n /= 10;
	}
	return true;
}
int main() {
	for(int i = 0; i < 10; i++) num[i] = 2021;
	int i = 1;
	while(comp(i) == true) {
		i++;
	}
	cout << i - 1 << endl;
	return 0;
}

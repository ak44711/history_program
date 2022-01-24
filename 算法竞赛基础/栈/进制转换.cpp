#include<iostream>
#include<stack>
#include<algorithm>
using namespace std; 
stack<char> stk;
char digit[] = "0123456789ABCDEFG";
void convert(int n, int base) {
	if(n == 0) return;
	stk.push(digit[n % base]);
	convert(n / base, base);
}
string convertIt(int n, int base) {
	string s;
	while(n != 0) {
		s.push_back(digit[n % base]);
		n /= base;
	}
	reverse(s.begin(), s.end());
	return s;
}
int main() {
	int n;
	cin >> n;
	convert(n, 16);
	while(!stk.empty()) {
		printf("%c", stk.top());
		stk.pop();
	}
	printf("\n");
	cout << convertIt(n, 16) << endl;
	return 0;
} 

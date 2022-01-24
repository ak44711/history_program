#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 10010;
int memo[maxn];
int fib(int n) {
	if(n <= 1) return n;
	else if(memo[n] != 0) return memo[n];
	return memo[n] = fib(n - 1) + fib(n - 2);
}
int main() {
	memset(memo, 0,sizeof(memo)) ;
	cout << fib(100) << endl;
	for(int i = 0; i < 1000; i++) {
		printf("%d ", memo[i]);
		if(i % 10 == 0) printf("\n");
	}
	return 0;
}

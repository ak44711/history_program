#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int Max = 1e3 + 20;
int res[Max] = {0};
int f(int idx, int tail) {
	int t = res[idx - 1] * res[idx - 2];
	if(t >= 10) {
		res[tail++] = t / 10;
		res[tail++] = t % 10;
	}else{
		res[tail++] = t;
	}
	return tail;
}
int main() {
	int a1,a2, n;
	cin >> a1 >> a2 >> n;
	res[0] = a1;
	res[1] = a2;
	int idx = 2, tail = 2;
	while(tail < n) {
		tail = f(idx, tail);
		idx++;
	}
	for(int i = 0; i < n; i++) {
		if(i == n - 1) {
			printf("%d\n", res[i]);
		}else{
			printf("%d ", res[i]);
		}
	}
	return 0;
}

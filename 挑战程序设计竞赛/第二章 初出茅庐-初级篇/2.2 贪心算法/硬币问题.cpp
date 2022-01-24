#include<iostream>
#include<cstdio>
#include<algorithm>
/*1,5,10,50,100,500各若干个,需要支付A元，需要多少个*/
using namespace std;
const int n = 6;
int num[n];
int w[n] = {1, 5, 10, 50, 100, 500};
int A;

int main() {
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]); 
	}
	scanf("%d", &A);
	int ans = 0;
	/*纯模拟 
	while(A > 0) {
		for(int i = n - 1; i >= 0; i--) {
			if(A >= w[i] && num[i] > 0) {
				printf("%d ", w[i]);
				A -= w[i];
				num[i]--;
				ans++;
				break;
			}
		}
	}*/
	for(int i = n - 1; i >= 0; i--) {
		int t = min(A / w[i], num[i]);
		A -= t * w[i];
		ans += t; 
		printf("%d * %d\n", t, w[i]);
	}
	printf("\n%d\n", ans);
	return 0;
}
/*
3 2 1 3 0 2 620
*/

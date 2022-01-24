#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5;
int w[N];
int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w, w + n);
	/*重量小的尽量多装*/
	for(int i = 0; i < n && c -w[i] > 0; i++) {
		c -= w[i];
		printf("%d ", w[i]);
	}
	printf("\n");
	return 0;
}
/*
10 100
11
9
54
21
16
12
14
13
11
10
*/

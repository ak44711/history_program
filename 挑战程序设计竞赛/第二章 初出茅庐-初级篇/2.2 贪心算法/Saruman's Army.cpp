#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn = 1010;
int N, R, X[maxn];
int main() {
	scanf("%d%d", &N, &R);
	for(int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	sort(X, X + N);
	int i = 0, ans = 0;
	while(i < N) {
		int pos1 = X[i++];
		while(i < N && X[i] <= pos1 + R) i++;
		int pos2 = X[i - 1];
		while(i < N && X[i] <= pos2 + R) i++;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
/*
6
10
1 7 15 20 30 50
*/

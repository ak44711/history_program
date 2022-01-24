#include<cstdio>
using namespace std;
int main() {
	int arr[40];
	arr[0] = 0;
	arr[1] = 3;
	arr[2] = 8;
	int n;
	for(int i = 3; i < 40; i++) {
		arr[i] = arr[i - 1] * 2 + arr[i - 2] * 2;
	}
	while(scanf("%d", &n)){
		printf("%lld\n",arr[n]);
	}
	return 0;
}

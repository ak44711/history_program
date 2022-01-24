#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	int arr[24];
	for(int i = 0; i < 24; i++) {
		scanf("%d", &arr[i]);
	}
	int idx;
	scanf("%d", &idx);
	while(0 <= idx && idx <= 23) {
		if(arr[idx] > 50) {
			printf("%d Yes\n", arr[idx]);
		}else{
			printf("%d No\n", arr[idx]);
		}
		scanf("%d", &idx);
	}
	return 0;
}

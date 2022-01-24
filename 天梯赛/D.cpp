#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	int N,M;
	cin >> N >> M;
	float price;
	for(int i = 0; i < N; i++) {
		scanf("%f",&price);
		if(price < M) {
			printf("On Sale! %.1f\n",price);
		}
	}
	return 0;
}

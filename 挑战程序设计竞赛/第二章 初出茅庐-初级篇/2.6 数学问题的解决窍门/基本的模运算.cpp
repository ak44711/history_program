#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll a, b;
int main() {
	a = INT_MAX - 10;
	b = INT_MAX - 10;
	printf("%d", (a * b) % 10);
	return 0;
}

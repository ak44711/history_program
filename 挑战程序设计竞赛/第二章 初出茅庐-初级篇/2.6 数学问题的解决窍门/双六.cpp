#include<cstdio>
using namespace std;
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int extgcd(int a, int b) {
	if(gcd(a, b) != 1) {
		return 0;	
	}
	
}

int main() {
	int a, b;
	//scanf("%d%d", &a, &b);
	printf("%d\n", gcd(2,5));
	printf("%d\n", gcd(3,6));
	return 0;
}

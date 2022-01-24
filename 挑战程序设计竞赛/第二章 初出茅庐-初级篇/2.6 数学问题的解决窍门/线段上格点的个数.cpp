#include<cstdio>
#include<cmath> 
using namespace std;
int gcd(int a, int b) {
	int t = a % b;
	if(t == 0) return b;
	return gcd(b, t);
}
int main() {
	int x1 = 1, y1 = 11;
	int x2 = 5, y2 = 3;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if(dx == 0 && dy == 0) {
		printf("0\n");
		return 0;
	}
	if(dx == 0) {
		printf("%d", dy - 1);
		return 0;
	}
	if(dy == 0) {
		printf("%d", dx - 1);
		return 0;
	}
	
	int ans = gcd(dx, dy);
	
	for(int i = 1; i < ans; i++) {
		printf("(%d, %d)\n", x1 + i * ((x2 - x1) / ans), y1 + i * ((y2 - y1) / ans));
	}
	printf("%d\n", ans - 1);
	return 0;
} 

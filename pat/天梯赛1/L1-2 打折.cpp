#include<iostream>
using namespace std;
int main() {
	int n, discount;
	cin >> n >> discount;
	printf("%.2f\n", 0.1 * n * discount);
	return 0;
}

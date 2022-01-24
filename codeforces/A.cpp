#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	long long n, m , x;
	long long arr[t];
	long long row, col;
	for(int i = 0; i < t; i++) {
		cin >> n >> m >> x;
		col = (x - 1) / n;
		row = (x - 1) % n;
		arr[i] = row * m + col + 1;
	}
	for(int i = 0; i < t; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}

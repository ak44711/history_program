#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

bool addone(vector<int>& arr, int m) {
	int size = arr.size();
	int t = 1;
	for(int i = 0; i < size; i++) {
		t = t + arr[i];
		arr[i] = t % m;
		t /= m;
	}
	for(int i = 0; i < size; i++) {
			
	}
	
}
 
int main() {
	int m, n;
	cin >> n >> m;
	vector<vector<int> > arr(n, vector<int> (m, 0));
	vector<vector<int> > sum(n, vector<int> (m + 1, 0));
	int t;
	int total = 0;
	for(int i = 0; i < n; i++ ) {
		for(int j = 0; j < m; j++) {
			cin >> t;
			arr[i][j] = t;
			sum[i][j + 1] = sum[i][j] + t;
			total += t;
		}
	}
	vector<int> v(n,0);
	int times = pow(m,n);
	int _total;
	for(int i = 0; i < times - 1; i++){
		addone(v, m);
		_total = 0;
		for(int j = 0;  < n; i++) {
				_total += sum[i][i + 1];
		}
		
	}
	
 	return 0;
}

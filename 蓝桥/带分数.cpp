#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int cnt;
int ret = 0;
int del(vector<int>& v) {
	int res = 0;
	int size = v.size();
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < size - 2; i++) {
		a = 0;
		for(int m = 0; m <= i; m++) {
			a = a * 10 + v[m];
		}
		for(int j = i + 1; j < size - 1; j++) {
			b = 0; c = 0;
			for(int m = i + 1; m <= j; m++) {
				b = b * 10 + v[m];
			}
			for(int m = j + 1; m < size; m++) {
				c = c * 10 + v[m];
			}
 			if(b % c == 0 && a + b / c == ret){
				
				res ++;
			}
		}
	}
	return res;
}

void dfs(vector<int>& v, int first, int len) {
	if(first == len ){
		if(del(v)){
			cnt++;
		}
		return;
	}
	for(int i = first; i < len; i++) {
		swap(v[first], v[i]);
		dfs(v, first + 1, len);
		swap(v[first], v[i]);
	}
	
}

int main() {
	cin >> ret;
	vector<int> arr(9);
	for(int i = 0; i < 9; i++) {
		arr[i] = i + 1;
	}
	dfs(arr, 0, 9);
	cout << cnt << endl;
	cout << pow(10, 10) << " " << INT_MAX;
	return 0;
}

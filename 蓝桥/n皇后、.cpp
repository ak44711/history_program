#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

int num = 0;

void dfs(vector<int>& v, int len, int first, vector<vector<bool> >& vv) {
	//该位置不能站人 
	if(first > 0 && vv[v[first - 1]][first - 1] == 0 ) return;
	//如果皇后互相攻击 
	for(int i = 0; i < first - 1; i++) {
		if(first - 1 - i == abs(v[first - 1] - v[i])){
			return;
		}
	}

	if(first == len) {
		num ++;
		return;
	}
	for(int i = first; i < len; i++) {
		swap(v[i], v[first]);
		dfs(v, len, first + 1, vv);
		swap(v[i], v[first]);
	}
}

int main() {
	
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		v[i] = i;
	}
	vector<vector<bool> > vv(n, vector<bool> (n));
	bool t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> t;
			vv[i][j] = t;
		}
	}
	dfs(v, n, 0, vv);
	cout << num * (num - 1) << endl;
}
/*
5
1 1 1 1 1 
1 0 1 1 1 
1 1 1 1 1 
1 0 1 1 1 
1 1 1 1 1 

7
1 1 1 1 1 1 0 
1 1 1 1 1 1 1 
1 1 1 1 1 1 1 
1 1 1 1 1 1 1 
1 1 1 1 1 1 1 
1 1 1 1 1 1 1 
1 1 1 1 1 1 1 
*/

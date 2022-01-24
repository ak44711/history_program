#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;
int k;
void dfs(int arr[], bool used[], vector<vector<bool> >& limit,vector<int>& stack,int depth, int len) {
	if(depth > 1 && limit[stack[depth - 2]][stack[depth - 1]] == false) return;
	if(depth == len) {
		cnt ++;
		if(cnt == k){
			for(int i = 0; i < len; i++) {
				cout << stack[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for(int i = 0; i < len; i++) {
		if(used[i] == false){
			stack.push_back(arr[i]);
			used[i] = true;
			dfs(arr, used, limit,stack,depth + 1, len);
			used[i] = false;
			stack.pop_back();
		}
	}
} 

int main() {
	int n;
	cin >> n >> k;
	int arr[n];
	bool used[n];
	for(int i = 0; i < n; i++) {
		arr[i] = i;
		used[i] = false;
	}
	vector<vector<bool> > limit(n, vector<bool>(n));
	bool t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> t;
			limit[i][j] = t;
		}
	}
	vector<int> stack;
 	dfs(arr, used, limit, stack,0, n);

	return 0;
}

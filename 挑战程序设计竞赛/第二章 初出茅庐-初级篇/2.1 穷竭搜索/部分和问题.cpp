#include<iostream>
using namespace std;
const int maxn = 22;
int arr[maxn];
bool flag = false;
int cnt = 0;
int n;
int k;
/*
void dfs(int aim, int n) {
	cnt++;
	if(aim == 0) {
		flag = true;
		return;
	}
	if(aim < 0) return;
	for(int i = n - 1; i >= 0; i--) {
		dfs(aim - arr[i], i);
	}
}
*/
bool dfs(int i, int sum) {
	cnt++;
	if(n == i) return sum == k;
	if(dfs(i + 1, sum)) return true;
	if(dfs(i + 1, sum + arr[i])) return true;
	return false;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
//	dfs(k,n);
//	if(flag) printf("yes\n");
//	else printf("no\n");
	if(dfs(0,0)) printf("yes\n");
	else printf("no\n");
	cout << cnt << endl;
	return 0;
}
/*
4
1 2 4 7
13

4
1 2 4 7
15
*/

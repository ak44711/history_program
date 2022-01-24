#include<iostream>
#include<vector>
using namespace std;
int parent[10100];
int rnk[10100];
int find_root(int a){
	while(a != parent[a]) {
		a = parent[a];
	}
	return a;
}
bool union_road(int a, int b) {
	int a_root = find_root(a);
	int b_root = find_root(b);
	if(a_root == b_root){
		return false;
	}
	if(rnk[a_root] > rnk[b_root]) {
		parent[b_root] = a_root;
	}else if(rnk[a_root] < rnk[b_root]){
		parent[a_root] = b_root;
	}else{
		parent[a_root] = b_root;
		rnk[b_root]++;
	}
	return true;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int beg, end;
	for(int i = 0; i < m; i++) {
		cin >> beg >> end;
		union_road(beg, end);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(i == parent[i]){
			cnt++;
		}
	}
	cout << cnt - 1 << endl;
	return 0;
}
/*
4 2
1 3
4 3

3 3
1 2
1 3
2 3

5 2
1 2
3 5

999 0

*/

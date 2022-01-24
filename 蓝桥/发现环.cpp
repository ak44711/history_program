#include<iostream>
#include<vector>
#include<list>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100000;
int father[MAX];
int depth[MAX];
int find_root(int x) {
	while(father[x] != -1) {
		x = father[x];
	}
	return x;
}
bool add(int x, int y) {
	int xx = find_root(x);
	int yy = find_root(x);
	if(xx == yy) {
		return true;
	}
	if(depth[xx] < depth[yy]) {
		father[xx] = yy;
	}else{
		father[yy] = xx;
	}
	return false;
}
bool used[MAX];
void dfs(int x, int y, vector<int>& stk,vector<vector<int> > &vl) {
	
	for(int i = 0; i < vl[x].size(); i++) {
		if(used[vl[x][i]] == false) {
			used[vl[x][i]] = true;
			stk.push_back(vl[x][i]);
			dfs(vl[x][i], y, stk, vl);
			stk.pop_back();
			used[vl[x][i]] = false;
		}
	}
}
int main() {
	memset(father, -1, sizeof(father));
	memset(used, false, sizeof(used));
	int n;
	cin >> n;
	vector<vector<int> > vl(n + 1);
	int beg, end;
	for(int i = 1; i <= n; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		vl[from].push_back(to);
		vl[to].push_back(from);
		if(add(from,to)) {
			beg = from;
			end = to;
		}
	}
	vector<int> stk;
	stk.push_back(beg);
	used[beg] = true; 
	dfs(beg, end, stk, vl);
	return 0;
}

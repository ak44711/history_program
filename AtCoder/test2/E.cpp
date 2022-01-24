#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;
bool used[100010] = {0};
int color[100010];
vector<list<int>> rela;
void dfs(int 1)
int main() {
	int n;
	cin >> n;
	rela.resize(n);
	for(int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	int a, b;
	for(int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		rela[a].push_back(b);
		rela[b].push_back(b);
	}
	return 0;
}

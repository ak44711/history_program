#include<cstdio>
#include<vector>
#include<cstring>
#include<queue> 
using namespace std;
const int maxn = 1010;
vector<int> M[maxn];
int n, e; 

bool used1[maxn] = {0};
bool used2[maxn] = {0};

void bfs(int v) {
	queue<int> que;
	que.push(v);
	used2[v] = true;
	while(!que.empty()) {
		int t = que.front();
		que.pop();
		printf("%d\n", t);
		for(int i = 0; i < M[t].size(); i++) {
			if(used2[M[t][i]] == false) {
				used2[M[t][i]] = true;
				que.push(M[t][i]);
			}
		}
	}
}
void dfs(int v) {
	printf("%d\n", v);
	//used1[v] = true;
	for(int i = 0; i < M[v].size(); i++) {
		if(used1[M[v][i]] == false) {
			dfs(M[v][i]);
		}
	}
}
int main() {
	memset(used1, 0, sizeof(used1));
	memset(used2, 0, sizeof(used2));
	scanf("%d%d", &n, &e);
	for(int i = 0; i < e; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		M[from].push_back(to);
		//M[to].push_back(from)
	}
	printf("***********bfs*****************\n");
	for(int i = 1; i <= n; i++) {
		if(used2[i] == false) {
			bfs(i);
		}
	}
	printf("***********dfs*****************\n");
	for(int i = 1; i <= n; i++) {//为什么需要for循环？考虑一下非连通图 
		if(used1[i] == false)
			dfs(i);
	}
	return 0;
} 

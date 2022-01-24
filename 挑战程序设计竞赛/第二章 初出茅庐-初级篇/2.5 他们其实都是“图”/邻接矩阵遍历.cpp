#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1010;
int M[maxn][maxn];
int n, e; 

bool used1[maxn] = {0};
bool used2[maxn] = {0};

void dfs(int v) {
	printf("%d\n", v);
	used1[v] = true;
	for(int i = 1; i <= n; i++) {
		if(used1[i] == false && M[v][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int> que;
	que.push(v);
	used2[v] = true;
	while(!que.empty()) {
		int t = que.front();
		printf("%d\n", t);
		que.pop();
		for(int i = 1; i <= n; i++) {
			if(M[t][i] == 1 && used2[i] == false) {
				used2[i] = true;
				que.push(i);
			}
		}
		
	}
} 

int main() {
	memset(M, 0, sizeof(M));
	memset(used1, 0, sizeof(used1));
	memset(used2, 0, sizeof(used2));
	scanf("%d%d", &n, &e);
	for(int i = 0; i < e; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		M[from][to] = 1;
		//M[to][from] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("***********dfs*****************\n");
	for(int i = 1; i <= n; i++) {//为什么需要for循环？考虑一下非连通图 
		if(used1[i] == false)
			dfs(i);
	}
	printf("***********bfs*****************\n");
	for(int i = 1; i <= n; i++) {
		if(used2[i] == false) {
			bfs(i);
		}
	}
	return 0;
}

/*
5 9
1 2
1 3
2 3
2 5
3 3
4 1
4 2
4 5
5 3
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e2 + 10;

int Dijkstra(int G[N][N], int n, int start) {
	int dist[N];//每一轮每条边距离start的路径 
	bool st[N] = {0};//已确定离start最短的点
	memset(dist, 0x3f, sizeof(dist));
	dist[start] = 0;
	for(int i = 0; i < n; i++) {
		/*找到不在s中距离start最短的点
		  将t加入s
		  用t更新其他的点
		*/
		int t = -1;
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j])) 
				t = j;
		st[t] = true;
		for(int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + G[t][j]);
		}
	}
	if(dist[n] == INF) return -1;
	return dist[n];
}
int main() {
    /*下标起点从1开始*/
	int n, m, from, to, w;
	scanf("%d%d", &n, &m);
	int G[N][N];
	memset(G, 0x3f, sizeof(G));
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &from, &to, &w);
		//可能会有重边，保留最短的 
		G[from][to] = min(G[from][to], w); 
	}
	printf("%d", Dijkstra(G,n, 1));
	return 0;
}

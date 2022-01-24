#include<iostream>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e2+10;
/*
0.假设所有点不连通，即所有点到集合的距离初始为INF 
1.找在集合外距离最近的点 t
2.如果t不是第一个点， 则会产生边，ans加上点t到集合的最短距离 
2.用t更新其他点到集合的距离
3.将t标记为集合内的点，s[t]=true 
*/
int Prim(int G[N][N], int n) {
	int dist[N];//点到集合的距离
	bool st[N] = {0};//在连通块中的点
	int res = 0; 
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 0; i < n; i++) {
		int t = -1;
		for(int j = 1; j <= n; j++) {
			//找到距离集合最小的点 
			if(!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
		/*如果不是第一个点并且图不联通，返回INF
		  寻找第一个点的时候所有距离都是INF所以不用管 
		  如果不是第一个点，集合外距离集合的最小距离还是正无穷，
		  	说明不连通
		*/
		if(i && dist[t] == INF) return INF;
		//选择第一个点的时候没有产生边,所以不加上权重 
		if(i) res += dist[t];
		for(int j = 1; j <= n; j++) dist[j] = min(G[t][j], dist[j]);
		//把点t加到集合里面去
		st[t] = true;
	}
	return res; 
}
int main() {
	int G[N][N],n, m;//图有n个顶点m条边 
	memset(G, 0x3f, sizeof(G));
	for(int i = 1; i <= n; i++) G[i][i] = 0;
	scanf("%d%d", &n, &m);
	int u, v, w;
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		//去重边，取重边权重最小的边 
		G[v][u] = G[u][v] = min(G[u][v], w);
	}
	int t = Prim(G, n);
	if(t == INF) printf("impossible\n");
	else printf("%d\n", t);
	return 0;
}

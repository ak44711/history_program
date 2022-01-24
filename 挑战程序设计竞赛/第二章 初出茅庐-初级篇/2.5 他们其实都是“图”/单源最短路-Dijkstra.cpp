#include<cstdio>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
const int INF = INT_MAX / 2;
int M[maxn][maxn];
int n, e; 
int beg, aim;

int d[maxn];//每个点到s最小的距离 
bool used[maxn];
void dijkstra(int s) {
	fill(d, d + n, INF);
	fill(used, used + n, false);
	d[s] = 0;
	while(true) {
		int v = -1;
		//从未使用过的点中选择到s最短的顶点 
		for(int i = 0; i < n; i++) {
			if(!used[i] && ( v == -1 || d[i] < d[v])) v = i;
		}
		if(v == -1) break;//全都更新过则推出 
		used[v] = true;
		for(int i = 0; i < n; i++) {
			d[i] = min(d[i], d[v] + M[v][i]);//v和i之间没有边，仍然为 ∞
		} 
	}
	
}

int main() {
	scanf("%d%d", &n, &e);
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			M[i][j] = INF;
		}
	}
	for(int i = 0; i < e; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		M[from][to] = cost;
		//M[to][from] = cost;
	}
	scanf("%d", &beg);
	dijkstra(beg);
	for(int i = 0; i < n; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}
/*
7 10
0 1 2
0 2 5
1 2 4 
2 3 2
1 3 6
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9
0 
*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10010;
const int maxe = 1e7 + 10;
const int INF = INT_MAX / 2;
typedef struct edge{
	int from;
	int cost;
	int to;
}egde; 
edge Edges[maxn];
int v, e;//v个顶点， e条边 

int dist[maxn];
void ford(int s)  {
	fill(dist, dist + maxn, INF);
	dist[s] = 0;
	for(int i = 0; i < v - 1; i++) {
		for(int i = 0; i < e; i++) {
			if(dist[Edges[i].to] > dist[Edges[i].from] + Edges[i].cost){
				dist[Edges[i].to] = dist[Edges[i].from] + Edges[i].cost;
			}
			/*无向图 
			if(dist[Edges[i].from] > dist[Edges[i].to] + Edges[i].cost){
				dist[Edges[i].from] = dist[Edges[i].to] + Edges[i].cost;
			}*/
		}
	}
}

int main() {
	scanf("%d%d", &v, &e);
	for(int i = 0; i < e; i++) {
		edge t;
		scanf("%d%d%d", &t.from, &t.to, &t.cost);
		Edges[i] = t;
	}
	int beg;
	scanf("%d", &beg);
	ford(beg);
	for(int i = 0; i < v; i++) {
		printf("%d ", dist[i]);
	}
	return 0;
}


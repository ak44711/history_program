#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1010;
const int INF = INT_MAX / 2;

typedef pair<int, int> P;// <min_dist, V>
struct edge{
	int to, cost;
};
vector<edge> M[maxn];

int n, e; 
int beg, aim;

int d[maxn];//每个点到s最小的距离 

void dijkstra(int s) {
	fill(d, d + n, INF);
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, s));
	while(!que.empty()) {
		P p = que.top(); que.pop();//取出队首元素
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0; i < M[v].size(); i++) {
			//d[M[v][i].to] = min(d[M[v][i].to], d[v] + M[v][i].cost);//v和i之间没有边，仍然为 ∞
			edge e = M[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
			
		}
	}
}

int main() {
	scanf("%d%d", &n, &e);
	for(int i = 0; i < e; i++) {
		int from;
		edge e;
		scanf("%d%d%d", &from, &e.to, &e.cost);
		M[from].push_back(e);
		//M[to].push_back(edge(from, e.cost));
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

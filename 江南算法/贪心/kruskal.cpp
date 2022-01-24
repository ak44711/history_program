#include<iostream>
#include<climits>
#include<algorithm> 
using namespace std;
const int maxn = 1e6; 
const int INF = INT_MAX;
//数据规模 
int m, n;
//每个边需要维护起点终点和权重 
struct edge{
	int from, to, cost;
}edges[maxn];

//并查集的每个节点需要维护father和height 
struct node{
	int father, height;
}ufSet[maxn];

//重写cmp，排序的时候按照这个规则排序 
bool cmp(edge& e1, edge& e2) {
	return e1.cost < e2.cost;
}

//定义根节点的父节点为自己 
int find_set(int x) {
	while(ufSet[x].father != x) 
		x = ufSet[x].father;
	return x;
}

/*
两个集合高度相同，随便将一个集合的代表作为两个集合的代表
两个集合高度不同，将高度低的集合放到高度搞得集合下，无需更新高度 
*/
void union_set(int x, int y) {
	if(x == y) return;
	if(ufSet[x].height < ufSet[y].height) { 
		ufSet[x].father = y;
	}else if(ufSet[x].height > ufSet[y].height){
		ufSet[y].father = x;
	}else{
		ufSet[x].father = y;
		ufSet[y].height++;
	}
}

int kruskal() {
	int ans = 0;
	int cnt = 0;
	//初始化并查集 
	for(int i = 0; i < n; i++) {
		ufSet[i].father = i;
		ufSet[i].height = 1;
	}
	//将边集按照权重从小到大排序 
	sort(edges, edges + m, cmp);
	for(int i = 0; i < m; i++) {
		int pa = find_set(edges[i].from); 
		int pb = find_set(edges[i].to);
		//如果两个节点不在同一个集合内 
		if(pa != pb) {
			union_set(pa, pb);
			ans += edges[i].cost;
			cnt++;
		}
	}
	if(cnt == n - 1)return ans;	
	else return INF;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edge e = {a, b, c};
		edges[i] = e; 
	}
	int ans = kruskal(); 
	if(ans != INF) cout << ans << endl;
	else cout << "impossible" << endl;	
} 

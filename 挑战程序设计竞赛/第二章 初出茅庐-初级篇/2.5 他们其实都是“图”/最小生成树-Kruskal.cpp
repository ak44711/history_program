#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;
struct edge{
	int from;
	int cost;
	int to;
};
bool cmp(edge& e1, edge& e2){
	return e1.cost < e2.cost;
}
edge es[maxn];
int v, e;

int root[maxn];
int weight[maxn];
int find_root(int x) {
	while(root[x] != -1) {
		x = root[x];
	}
	return x;
}
void merge(int x, int y) {
	if(weight[x] < weight[y]) {
		root[x] = y;
	}else {
		root[y] = x;
	}
}

int kruskal() {
	int cnt = 0;
	int i = 0;
	int ans = 0;
	fill(root, root + v, -1);
	fill(weight, weight + v, 0);
	while(cnt < v - 1) {
		int x = es[i].from;
		int y = es[i].to;
		x = find_root(x);
		y = find_root(y);
		if(x != y) {
			merge(x, y);
			ans += es[i].cost;
			cnt++;
		}
		i++;
	}
	return ans;
}

int main()  {
	scanf("%d%d", & v, &e);
	for(int i = 0; i < e; i++) {
		edge t;
		scanf("%d%d%d", &t.from, &t.to, &t.cost);
		es[i] = t;
	}
	sort(es, es + e, cmp);
	printf("%d\n", kruskal());
	return 0;
}
/*
6 10
0 1 6
0 3 5
0 2 1
1 2 5
2 3 5
1 4 3
4 5 6
3 5 2
2 4 6
2 5 4
*/

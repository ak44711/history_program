#include<iostream>
#include<climits>
#include<algorithm> 
using namespace std;
const int maxn = 1e6; 
const int INF = INT_MAX;
//���ݹ�ģ 
int m, n;
//ÿ������Ҫά������յ��Ȩ�� 
struct edge{
	int from, to, cost;
}edges[maxn];

//���鼯��ÿ���ڵ���Ҫά��father��height 
struct node{
	int father, height;
}ufSet[maxn];

//��дcmp�������ʱ��������������� 
bool cmp(edge& e1, edge& e2) {
	return e1.cost < e2.cost;
}

//������ڵ�ĸ��ڵ�Ϊ�Լ� 
int find_set(int x) {
	while(ufSet[x].father != x) 
		x = ufSet[x].father;
	return x;
}

/*
�������ϸ߶���ͬ����㽫һ�����ϵĴ�����Ϊ�������ϵĴ���
�������ϸ߶Ȳ�ͬ�����߶ȵ͵ļ��Ϸŵ��߶ȸ�ü����£�������¸߶� 
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
	//��ʼ�����鼯 
	for(int i = 0; i < n; i++) {
		ufSet[i].father = i;
		ufSet[i].height = 1;
	}
	//���߼�����Ȩ�ش�С�������� 
	sort(edges, edges + m, cmp);
	for(int i = 0; i < m; i++) {
		int pa = find_set(edges[i].from); 
		int pb = find_set(edges[i].to);
		//��������ڵ㲻��ͬһ�������� 
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

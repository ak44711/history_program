#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 1010;
const int INF = INT_MAX / 2;

typedef pair<int, int> P;// <min_dist, V>
struct edge{
	int to, cost;
};
vector<edge> M[maxn];

int n, e; 
/*
��δѡ��ĵ���ѡ��һ���㣬ʹ�øõ㵽��ѡ��ĵ���ɵ�����Ȩ����С
*/
int prim() {
	vector<bool> selected(n,false);
	selected[0] = true;
	int ans = 0;
	for(int j = 0; j < n; j++) {
			cout << selected[j] << " ";
	}
	printf("--%d--\n", 0);
	for(int i = 0; i < n - 1; i++) {//ѡ��n-1���� 
		int v;
		int mincost = INT_MAX;
		for(int j = 0; j < n; j++) {//��ѡ���ĵ�
			if(selected[j] == false) continue;
			for(int k = 0; k < M[j].size(); k++) {//��Щ�������ӵı� 
				if(selected[M[j][k].to] == false && mincost > M[j][k].cost) {
					v = M[j][k].to;
					mincost = M[j][k].cost;
				}
			}
		}
		selected[v] = true;
		for(int j = 0; j < n; j++) {
			cout << selected[j] << " ";
		}
		printf("--%d-- \n", v);
		
		ans += mincost;
	}
	printf("\n");
	return ans;
} 

int main() {
	scanf("%d%d", &n, &e);
	for(int i = 0; i < e; i++) {
		int from, to, cost;
		edge e;
		scanf("%d%d%d", &from, &to, &cost);
		e.to = to;
		e.cost = cost;
		M[from].push_back(e);
		e.to = from;
		M[to].push_back(e);
	}
	
	printf("%d", prim());
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

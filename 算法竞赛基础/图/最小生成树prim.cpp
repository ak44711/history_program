#include<iostream>
#include<list>
#include<cstring>
#define N 10010
#include<queue>
using namespace std;
int n, m;//n个顶点，m条边 
int weights[N][N];//权重网
int mincost[N];
int used[N];

int prim() {
	memset(mincost, INT_MAX, sizeof(mincost));
	mincost[1] = 0;//先选定1 
	int ans = 0;
	while(true) {
		int v = -1;
		for(int u = 1; u <= n; u++) {
			if(!used[u] && (v == -1) || mincost[u] < mincost[v]) v = u;
		}
	} 
	queue<int> q;
	q.ba
	return ans;
}
 
int main() {
	memset(head, -1, sizeof(head));
	cnt = 1;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		weights[from][to] = weight;
		weights[to][from] = weight; 
	}
	cout << prim() << endl;
	return 0;
} 

#include<algorithm>
sort(type* begin, type* end + 1)
bool cmp(type& v1, type& v2) {
	return v1.attribute < v2.attribute
}
sort(type* begin, type* end + 1, cmp)

#include<queue>
queue<type> que
	que.front()
	que.back()
	que.push()
	que.pop() 
	que.size()
	que.empty()
priority_queue<type> pq
	pq.push()
	pq.pop()
	pq.top()
	pq.empty()
	pq.size()

#include<stack>
stack<type> stk
	stk.top()
	stk.push()
	stk.pop() 
	stk.size()
	stk.empty()

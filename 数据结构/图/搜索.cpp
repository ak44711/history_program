#include<iostream>
#include<cstring>
#include<queue> 
using namespace std;
const int N = 1e3 + 10;

bool visited[N] = {0};
/*
假设初始状态就是图中所有顶点都未曾被访问
则深度优先遍历可以从图中某个顶点v出发，访问此节点
然后一次从v的未被访问的临界点出发深度优先遍历图，知道图中所有和v路径相同的顶点都被访问到
若此时图中尚有顶点违背访问到，则另选图中另一个未被访问的顶点作为起始点
重复此操作，直至所有顶点都被访问到为止。 
*/
void dfs(bool G[N][N], int n, int cur) {
	cout << cur << " ";
	visited[cur] = true;
	for(int i = 1; i <= n; i++) {
		if(G[cur][i] == 1 && !visited[i]) {
			dfs(G, n, i);
		}
	}
}

void bfs(bool G[N][N], int n, int cur) {
	memset(visited, 0, sizeof(visited));
	queue<int> que;
	que.push(cur);
	while(!que.empty()) {
		int t = que.front();
		que.pop();
		if(visited[t]) continue;
		cout << t << " ";
		visited[t] = true;

		for(int i = 1; i <= n; i++) {
			if(G[t][i] == true && !visited[i]) {
				que.push(i);
			}
		}
	}
}
int main() {
	bool G[N][N];
	memset(G, 0, sizeof(G));
	int n, m, a, b;
	cin >> n >> m;
	while(m--) {
		cin >> a >> b;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	cout << endl;
	dfs(G, n, 1);
	cout << endl;
	bfs(G, n, 1);
	return 0;
}
/*
8 9
1 2
2 4
2 5
4 8
5 8
1 3
3 6
6 7
3 7
*/

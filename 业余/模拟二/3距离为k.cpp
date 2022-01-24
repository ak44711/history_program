/*
利用广度优先搜索的性质， 总是按层遍历，每次遍历的节点距离源点总是非递减的
但是遍历的时候我们不知道具体的距离是多少，所以我们需要记录下距离 
*/
void bfs(int* G[N], int col[N], int x, int k) {
	queue<int> que;
	bool used[N];
	int dist[N];
	que.push(x);
	dist[x] = 0;
	used[x] = true;
	while(!que.empty()) {
		int t = que.head;
		que.pop();
		if(dist[t] == k) cout << t << " ";
		for(int i = 0; i < col[t]; i++) {
			if(!used[i]) {
				que.push(G[t][i]);
				dist[G[t][i]] = dist[t] + 1;
			}
		}
	}
	cout << endl;
} 

/*
���ù���������������ʣ� ���ǰ��������ÿ�α����Ľڵ����Դ�����Ƿǵݼ���
���Ǳ�����ʱ�����ǲ�֪������ľ����Ƕ��٣�����������Ҫ��¼�¾��� 
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

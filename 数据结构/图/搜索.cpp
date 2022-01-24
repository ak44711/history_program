#include<iostream>
#include<cstring>
#include<queue> 
using namespace std;
const int N = 1e3 + 10;

bool visited[N] = {0};
/*
�����ʼ״̬����ͼ�����ж��㶼δ��������
��������ȱ������Դ�ͼ��ĳ������v���������ʴ˽ڵ�
Ȼ��һ�δ�v��δ�����ʵ��ٽ�����������ȱ���ͼ��֪��ͼ�����к�v·����ͬ�Ķ��㶼�����ʵ�
����ʱͼ�����ж���Υ�����ʵ�������ѡͼ����һ��δ�����ʵĶ�����Ϊ��ʼ��
�ظ��˲�����ֱ�����ж��㶼�����ʵ�Ϊֹ�� 
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

#include<iostream>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e2+10;
/*
0.�������е㲻��ͨ�������е㵽���ϵľ����ʼΪINF 
1.���ڼ������������ĵ� t
2.���t���ǵ�һ���㣬 �������ߣ�ans���ϵ�t�����ϵ���̾��� 
2.��t���������㵽���ϵľ���
3.��t���Ϊ�����ڵĵ㣬s[t]=true 
*/
int Prim(int G[N][N], int n) {
	int dist[N];//�㵽���ϵľ���
	bool st[N] = {0};//����ͨ���еĵ�
	int res = 0; 
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 0; i < n; i++) {
		int t = -1;
		for(int j = 1; j <= n; j++) {
			//�ҵ����뼯����С�ĵ� 
			if(!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
		/*������ǵ�һ���㲢��ͼ����ͨ������INF
		  Ѱ�ҵ�һ�����ʱ�����о��붼��INF���Բ��ù� 
		  ������ǵ�һ���㣬��������뼯�ϵ���С���뻹�������
		  	˵������ͨ
		*/
		if(i && dist[t] == INF) return INF;
		//ѡ���һ�����ʱ��û�в�����,���Բ�����Ȩ�� 
		if(i) res += dist[t];
		for(int j = 1; j <= n; j++) dist[j] = min(G[t][j], dist[j]);
		//�ѵ�t�ӵ���������ȥ
		st[t] = true;
	}
	return res; 
}
int main() {
	int G[N][N],n, m;//ͼ��n������m���� 
	memset(G, 0x3f, sizeof(G));
	for(int i = 1; i <= n; i++) G[i][i] = 0;
	scanf("%d%d", &n, &m);
	int u, v, w;
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		//ȥ�رߣ�ȡ�ر�Ȩ����С�ı� 
		G[v][u] = G[u][v] = min(G[u][v], w);
	}
	int t = Prim(G, n);
	if(t == INF) printf("impossible\n");
	else printf("%d\n", t);
	return 0;
}

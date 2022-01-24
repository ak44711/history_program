#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 10000;
int A[maxn];
int B[maxn];
int P, L;
int n;
int main() {
	scanf("%d%d%d", &n, &L, &P);
	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}
	priority_queue<int> que;
	int pos = 0;
	int ans = 0;
	int tank = P;
	/*
	���ȶ����д洢�����ʸ���͵ļ���վ������ȱ�͵Ļ��ȼ����ȶ����������� 
	�ж�������������ܷ񵽴���һ����
		������ܣ�
			�����ȶ�������ȡ��
				�͹����ж���һ�� 
				���Ϳɼӣ�����-1
		����ܣ�
			�ж��ܷ񵽴���һ�� 
	*/
	for(int i = 0; i < n; i++) {
		int d = A[i] - pos;
		while(tank - d < 0) {
			if(que.empty()) {
				printf("-1\n");
				return 0;
			}
			tank += que.top();
			printf("��%d�� ", que.top());
			que.pop();
			ans++;
		}
		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	while(!que.empty()) {
		printf("��%d�� ",que.top());
		que.pop();
	}
	printf("%d\n", ans);
	return 0;
} 
/*
4 25 10
10 14 20 21
10 5 2 4
*/

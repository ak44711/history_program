#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring> 
4const int N = 101;
const int M = 1005;
struct Node{
	int apple;
	int delicious;
	int pick;//��ժʱ�� 
	int no;//ƻ������� 
}a[N];
int n, m, i, j, r, app, del, pic, Max;
int f[M][N], adj[N][N];
bool cmp(Node a, Node b) {
	return a.apple < b.apple;
}
int main() {
	scanf("%d %d", &n, &m);//n������ m��ʱ�� 
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &app, &del, &pic);//���Ӹ��� ��ֵ ʱ��
		a[i].apple = app;
		a[i].delicious = del;
		a[i].pick = pic;
		a[i].no = no; 
	}
	for(int i = 1; i <= n; i++) {//�����i����j������ʱ�� 
		for(int j = 1; j <= n; j++) {
			scanf("%d", adj[i][j]);
		}
	}
	sort 
	return 0;
}

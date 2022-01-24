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
	int pick;//采摘时间 
	int no;//苹果树编号 
}a[N];
int n, m, i, j, r, app, del, pic, Max;
int f[M][N], adj[N][N];
bool cmp(Node a, Node b) {
	return a.apple < b.apple;
}
int main() {
	scanf("%d %d", &n, &m);//n棵树， m的时间 
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &app, &del, &pic);//果子个数 价值 时间
		a[i].apple = app;
		a[i].delicious = del;
		a[i].pick = pic;
		a[i].no = no; 
	}
	for(int i = 1; i <= n; i++) {//输入第i到第j颗树的时间 
		for(int j = 1; j <= n; j++) {
			scanf("%d", adj[i][j]);
		}
	}
	sort 
	return 0;
}

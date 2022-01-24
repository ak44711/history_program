#include<iostream>
#include<cstring>
#include<cstdio> 
#include<map>
#include<queue>
using namespace std;
/*alias*/
typedef pair<int, int> pos;
/*data*/ 
const int INF = INT_MAX / 4;
const int maxn = 110;
//��ͼ 
char maze[maxn][maxn];
//S����������������· 
int d[maxn][maxn];
int n, m;
pos beg, aim;
/*function*/
int bfs() {
	//�ĸ����� 
	int dir[4][2] = {{-1,0}, {1, 0}, {0,1}, {0,-1}};
	//���� 
	queue<pos> que;
	//�����������,������һ��ľ�����Ϊ0 
	que.push(beg);
	d[beg.first][beg.second] = 0;
	//nowΪ��ͷλ�ã� 
	pos now;
	while(!que.empty()) {
		//��ȡ��ͷ���� 
		now = que.front();
		//�����ͷΪĿ������ 
		if(now == aim) break;
		//��ͷ���� 
		que.pop();
		//�жϺͶ�ͷ�ڽӵ������Ƿ��������� 
		for(int i = 0; i < 4; i++) {
			int row = now.first + dir[i][0];
			int col = now.second + dir[i][1];
			if(0 <= row && row < n && 0 <= col && col < m && d[row][col] == INF && maze[row][col] != '#') {
				d[row][col] = d[now.first][now.second] + 1;
				que.push(make_pair(row, col));
			}
		}
	}
	//�յ㴦��d������ʱans 
	return d[now.first][now.second];
}
int main() {
	//cin
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		getchar();
		for(int j = 0; j < m; j++) {
			scanf("%c", &maze[i][j]);
		}
	}
	//init
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			d[i][j] = INF;
			if(maze[i][j] == 'S') {
				beg = make_pair(i,j);
			}
			if(maze[i][j] == 'G') {
				aim = make_pair(i, j);
			}
		}
	}
	//procrss
	int ans = bfs();
	//cout
	cout << ans << endl;
	return 0;
} 
/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/

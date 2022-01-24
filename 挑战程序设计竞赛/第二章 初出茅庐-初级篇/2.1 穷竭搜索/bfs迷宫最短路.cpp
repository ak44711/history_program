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
//地图 
char maze[maxn][maxn];
//S到达其他各点的最短路 
int d[maxn][maxn];
int n, m;
pos beg, aim;
/*function*/
int bfs() {
	//四个方向 
	int dir[4][2] = {{-1,0}, {1, 0}, {0,1}, {0,-1}};
	//队列 
	queue<pos> que;
	//将起点加入队列,并将这一点的距离设为0 
	que.push(beg);
	d[beg.first][beg.second] = 0;
	//now为队头位置， 
	pos now;
	while(!que.empty()) {
		//获取队头坐标 
		now = que.front();
		//如果队头为目标坐标 
		if(now == aim) break;
		//队头出队 
		que.pop();
		//判断和队头邻接的坐标是否满足条件 
		for(int i = 0; i < 4; i++) {
			int row = now.first + dir[i][0];
			int col = now.second + dir[i][1];
			if(0 <= row && row < n && 0 <= col && col < m && d[row][col] == INF && maze[row][col] != '#') {
				d[row][col] = d[now.first][now.second] + 1;
				que.push(make_pair(row, col));
			}
		}
	}
	//终点处的d变量即时ans 
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

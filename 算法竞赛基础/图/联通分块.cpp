#include<iostream>
#include<queue>
#define N 110
using namespace std;
char Map[N][N];
bool visited[N][N];
int neibour[8][2] = {
	{-1,-1},{0,1},{1,1},
	{-1,0},   	  {1,0},
	{-1,1},{0,-1},{1,-1}
};
typedef struct pos{
	int x, y;
}pos;
void bfs(int x, int y) {
	pos now;
	now.x = x;
	now.y = y;
	queue<pos> que;
	que.push(now);
	while(!que.empty()) {
		now = que.front();
		que.pop();
		for(int i = 0; i < 8; i++) {
			int xx = now.x + neibour[i][0];
			int yy = now.y + neibour[i][1];
			if(Map[xx][yy] == '@' && visited[xx][yy] == false) {
				visited[xx][yy] = true;
				pos next;
				next.x = xx;
				next.y = yy;
				que.push(next);
			}
		}
	}
}
int main() {
	int row, col;
	cin >> row >> col;
	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) {
			scanf(" %c", &Map[i][j]);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) {
			if(Map[i][j] == '@' && visited[i][j] == false) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
} 
/*
3 5
*@*@*
**@**
*@*@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
*/

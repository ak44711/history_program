#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 110;
string garden[maxn];
int row,col, ans = 0;
bool used[maxn][maxn] = {false};

int dir[8][2] = {{-1, -1}, {-1, 0}, {-1,1},
				 {0, -1},{0,1},
			 	 {1, -1}, {1, 0}, {1, 1}
};

void DFS(int r, int c) {
	used[r][c] = true;
	for(int i = 0; i < 8; i++) {
		int rr = r + dir[i][0];
		int cc = c + dir[i][1];
		if(0 <= rr && rr < row && 0 <= cc && cc < col  && garden[rr][cc] == 'w' && used[rr][cc] == false) {
			DFS(rr, cc);
		}
	}
}

void dfs() {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(garden[i][j] == 'w' && used[i][j] == false) {
				ans++;
				DFS(i,j);
				for(int ii = 0; ii < row; ii ++) {
					for(int jj = 0; jj < col; jj++) {
						cout << used[ii][jj];
					}
					cout << endl;
				}
				cout << endl << endl;
			}
		}
	}
}

int main() {
	memset(used, false, sizeof(used));
	scanf("%d%d", &row, &col);
	for(int i = 0; i < row; i++) {
		cin >> garden[i];
	}
	dfs();
	cout << ans << endl;

	return 0;
} 
/*
10 12
w........ww.
.www.....www
....ww...ww.
.........ww.
.........w..
..w......w..
.w.w.....ww.
w.w.w.....w.
.w.w......w.
..w.......w.

*/

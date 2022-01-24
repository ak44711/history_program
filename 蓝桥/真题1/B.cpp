#include<cstdio>
#include<cstring>
using namespace std;
bool m[10000][10000];
int dir[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1,0}};
int main() {
	memset(m, 0, sizeof(m));
	int ipx = 3000;
	int ipy = 3000;
	m[0 + ipx][0 + ipy] = 1;
	m[2020 + ipx][11 + ipy] = 1;
	m[11 + ipx][14 + ipy] = 1;
	m[2000 + ipx][2000 + ipy] = 1;
	for(int i = 1; i <= 2020; i++) {
		for(int j = 0; j < 5000; j++) {
			for(int k = 0; k < 5000; k++) {//2e3 * 5e3 * 5e3 = 5e10
				if(m[j + ipx][k+ ipy] == 1) {
					for(int l = 0; l < 4; l++) {//2e3 * 5e3 * 5e3 * 4 = 2e10
						int xx = j + dir[l][0] + ipx;
						int yy = k + dir[l][1] + ipy;
						m[xx][yy] = 1;
					}
				}
			}
		}
		printf("-");
	}
	int ans = 0;
	
	for(int j = 0; j < 10000; j++) {
		for(int k = 0; k < 10000; k++) {
			if(m[j][k] == 1) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}

#include<iostream>
#define MAX 100;
using namespace std;
int map[MAX][MAX];
int main() {
	int min;
	int n, m;
	int xPoint[MAX];
	int yPoint[MAX];
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> xPoint[i] >> yPoint[i];
	}
	int maxx = -1, maxy = -1;
	int minx = MAX + 1, miny = MAX + 1;
	for(int i = 0; i < n; i++) {
		minx = min(xPoint[i], minx);
		miny = min(yPoint[i], miny);
		maxx = max(xPoint[i], maxx);
		maxy = max(yPoint[i], maxy);
	}
	
	return 0;
}

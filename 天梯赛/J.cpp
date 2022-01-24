#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
void bfs(vector<vector<int> > vv, vector<int>, )
int main() {
	int N;
	cin >> N;
	vector<vector<int> > vv(N);
	for(int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		vv[i].resize(N);
		for(int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			vv[i][j] = child;
		}
	}
	return 0;
}

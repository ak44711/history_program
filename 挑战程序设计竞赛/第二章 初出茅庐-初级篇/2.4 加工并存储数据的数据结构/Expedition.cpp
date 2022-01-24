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
	优先队列中存储了有资格加油的加油站油量，缺油的话先加优先队列中最多的油 
	判断利用油箱的油能否到达下一个油
		如果不能：
			向优先队列中索取油
				油够：判断下一个 
				无油可加：返回-1
		如果能：
			判断能否到达下一个 
	*/
	for(int i = 0; i < n; i++) {
		int d = A[i] - pos;
		while(tank - d < 0) {
			if(que.empty()) {
				printf("-1\n");
				return 0;
			}
			tank += que.top();
			printf("加%d油 ", que.top());
			que.pop();
			ans++;
		}
		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	while(!que.empty()) {
		printf("有%d油 ",que.top());
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

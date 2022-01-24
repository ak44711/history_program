#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 1010;
struct Work{
	int time;
	int score;
	friend bool operator < (const Work& a, const Work& b) {
		return a.score > b.score;
	}
} work[N];
bool done[N];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &work[i].time);
		for(int i = 1; i <= n; i++) scanf("%d", &work[i].score);
		sort(work + 1, work + 1 + n);

		int ans = 0;
		memset(done, false, sizeof(done));
		for(int i = 1;  i <= n; i++) {
			if(done[work[i].time]){
				int x = work[i].time;
				while(x && done[x]) x--;
				if(x) done[x] = true;
				else ans += work[i].score;
			}else{
				done[work[i].time] = true;
			}
		}
		printf("ans = %d\n", ans);
	}
	return 0;
	
} 
/*
3
3
3 3 3
10 5 1
3
1 3 1
6 2 7
7
1 4 6 4 2 4 3
3 2 1 7 6 5 4
*/

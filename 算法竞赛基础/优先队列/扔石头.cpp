#include<iostream>
#include<queue>
using namespace std;
struct rock{
	int pos;
	int dst;
	rock(int pos, int dst):pos(pos), dst(dst){}
	friend bool operator < (const rock& r1, const rock& r2) 
	{
		if(r1.pos == r2.pos) {
			return r1.dst > r2.dst;
		}
		return r1.pos > r2.pos;
	}
};
int main() {
	int t;
	while((cin >> t)){
		priority_queue<rock> que;
	int n;
	rock r(0, 0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> r.pos >> r.dst;
		que.push(r);
	}
	int cnt = 1;
	while(!que.empty()) {
		r = que.top(), que.pop();
		if(cnt % 2 == 1) {
			r.pos += r.dst;
			que.push(r);
		}
		cnt++;
	}
	cout << r.pos << endl;
	}
 	return 0;
} 
/*
2
1 5
2 4
2
1 5
6 6
*/

#include<iostream>
#include<queue> 
using namespace std;
void shut(queue<int>& q, int interval) {
	int i = 1;
	int first = q.front();
	int t;
	do{
		if(i % interval != 0) {
			q.push(q.front());
		}
		i++;
		q.pop();
	}while(q.front() != first);
}
int main() {
	int t;
	int n;
	queue<int> que;
	cin >> t;
	int turn = 0;
	for(int i = 0; i < t; i++) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			que.push(i);
		}
		while(que.size() > 3) {
			if(turn % 2 == 0) {
				shut(que, 2);
			}else{
				shut(que, 3);
			}
		}
		while(!que.empty()) {
			printf("%d ", que.front());
			que.pop();
		}
		printf("\n");
	}
	return 0;
}

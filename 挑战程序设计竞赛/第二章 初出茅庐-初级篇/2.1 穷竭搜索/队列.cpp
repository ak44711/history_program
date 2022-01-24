#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	printf("%d\n",que.front());
	printf("%d\n",que.back());
	return 0;
} 

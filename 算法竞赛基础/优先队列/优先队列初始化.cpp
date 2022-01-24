#include<queue>
#include<cstdio>
#include<vector>

using namespace std;

struct node{
	int x, y;
	node(){};
	node(int x, int y) : x(x), y(y){}
	bool operator <(const node& t) const{return x < t.x;};
};

int main() {
	priority_queue<int, vector<int>, greater<int> > que1;
	que1.push(1); 
	que1.push(2); 
	que1.push(3); 
	printf("%d\n",que1.top());
	
	priority_queue<node> que2;
	que2.push(node(1,2));
	que2.push(node(2,3));
	que2.push(node(3,4));
	printf("%d\n", que2.top().x);
	return 0;
}

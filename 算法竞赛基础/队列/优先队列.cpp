#include<iostream>
#include<queue> 
using namespace std; 
/*API:
	pop():void
	push(T x):void
	size():unsigned int
	empty():bool
	top():reference
*/ 
struct Node{
	int x, y;
	Node(int x, int y):x(x), y(y){}
	friend bool operator < (const Node& a, const Node& b) {
		return a.x < b.x;
	}	
};
int main() {
	priority_queue<int> que1;
	priority_queue<Node> que2;
	priority_queue<int, vector<int>, greater<int>> que3;
	priority_queue<int, vector<int>, less<int>> que4;
	que1.push(1);que3.push(1); que4.push(1);
	que1.push(4);que3.push(4); que4.push(4);
	que1.push(7);que3.push(7); que4.push(7);
	que1.push(5);que3.push(5); que4.push(5);
	que2.push(Node(1,4));que2.push(Node(7,2));
	que2.push(Node(2,5));que2.push(Node(5,3));
	cout << "que1:";
	while(!que1.empty()) {cout << que1.top() << " "; que1.pop();}
	cout << endl << "que2:";
	while(!que2.empty()) {cout << que2.top().x << " " << que2.top().y << ", "; que1.pop();}
	cout MM 
	cout << endl << "que2:";
	
	return 0;
} 

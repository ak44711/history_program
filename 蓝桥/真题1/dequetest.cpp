#include<deque>
#include<iostream>
using namespace std;
int main() {
	deque<char> que;
	que.push_back('a');
	que.push_back('b');
	que.push_front('c');
	
	cout << que.front();
	que.pop_front();
	
	cout << que.front();
	que.pop_front();
	
	que.push_front('d');
	
	cout << que.front();
	que.pop_front();
	
	cout << que.front();
	que.pop_front();
}

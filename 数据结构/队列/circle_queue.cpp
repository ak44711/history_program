#include<iostream>
using namespace std;

struct circle_queue {
	int* arr;	
	int head, tail;
	int maxsize;
	circle_queue(int len){
		head = tail = 0;
		maxsize = len + 1;
		arr = new int[maxsize];
	}
	bool empty(){
		return head == tail;
	}
	/*浪费一个空间*/
	bool full() {
		return (tail + 1 ) % maxsize == head;
	}
	void push(int x) {
		if(full()) {
			cout << "full" << endl;
			return;
		}
		arr[tail] = x;
		tail = (tail + 1) % maxsize;
		cout << back() << " ";
	}
	void pop() {
		if(empty()) {
			cout << "empty" << endl;
			return;
		}
		cout << front() << " ";
		head = (head + 1) % maxsize;
	}
	int front() {
		if(empty()) {
			cout << "empty" << endl;
			return -1;
		}
		return arr[head];
	}
	int back() {
		if(empty()) {
			cout << "empty" << endl;
			return -1;
		}
		return arr[tail - 1];
	}
}; .

int main() {
	/*test*/
	circle_queue que(10);
	for(int i = 0; i < 11; i++) {
		que.push(i);
	}
	cout << endl << "pop" << endl;
	for(int i = 0; i < 11; i++) {
		que.pop();
	}
	
	return 0;
} 

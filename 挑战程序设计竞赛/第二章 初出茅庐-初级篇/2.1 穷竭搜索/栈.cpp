#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> stk;
	stk.pop();
	stk.pop();
	stk.push(1);
	stk.push(1);
	stk.push(1);
	cout << stk.top() << endl;
	return 0;
}

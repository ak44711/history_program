#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;
int main() {
    stack<bool> stk;
   	int n;
   	cin >> n;
   	bool input[n];
   	char c;
   	for(int i = 0; i < n; i++) {
   		cin >> c;
   		input[i] = c == 'T';
	}
	char st[500];
 	scanf(" %[^\n]",st);
 	int len = strlen(st);
 	char a,b;
 	for(int i = 0; i < len; i++) {
 		if(st[i] == ' ') {
 			continue;
		}else if(st[i] == '*'){
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(a && b);
		}else if(st[i] == '+'){
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(a || b);
		}else if(st[i] == '-'){
			a = stk.top();
			stk.pop();
			stk.push(!a);
		}else{
			stk.push(input[st[i] - 'A']);
		}
	}
	bool t = stk.top();
	cout << (t == 1? "T" : "F")<< endl;
}

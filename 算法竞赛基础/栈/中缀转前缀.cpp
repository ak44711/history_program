#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;
bool cmp_pri(char punc1, char punc2) {
	if(punc1 == )
}
int main() {
	stack<char> stk;
	string s;
	string line;
	getline(cin, line);
	while(!line.empty()) {
		if(isdigit(line[i])) {
			s+=line[i];
		}
		if(ispunct(line[i])) {
			if(cmp_pri(line[i], stk.top()) == true) {//
				
			}
		}
	}
	return 0;
} 

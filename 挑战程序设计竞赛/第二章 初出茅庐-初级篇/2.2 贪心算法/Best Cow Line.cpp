#include<cstdio>
#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main() {
	string s;
	string t;
	int n;
	scanf("%d", &n);
	cin >> s;
	deque<char> que(s.begin(), s.end());
	while(!que.empty()) {
		if(que.front() < que.back()) {
			t += que.front();
			que.pop_front();
		}else {
			t += que.back();
			que.pop_back();
		}
	}
	cout << t << endl;
	return 0;
}
/*
6
ACDBCB
*/

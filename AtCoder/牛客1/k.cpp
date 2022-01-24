#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
struct st{
	int ith;
	char c;
};
bool cmp(struct st st1, struct st st2) {
	if(st1.c == st2.c){
		return st1.ith < st2.ith;
	}
	return st1.c < st2.c;
}
int main() {
	int res = 0;
	string s;
	cin >> s;
	int len = s.size();
	vector<struct st> v(len);
	for(int i = 0; i < len; i++) {
		v[i].ith = i;
		v[i].c = s[i];
	}
	sort(v.begin(), v.end(), cmp);
	
	return 0;
} 

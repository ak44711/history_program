#include<iostream>
#include<string>
#include<vector>
using namespace std;

int f(string s, int k) {
	if(s.size() == 1) {
		return (int)(s[0] == '*');
	}
	
	int res = 0;
	int front = 0, back = s.size() - 1;
	while(s[front] != '*') {
		front++;
	}
	while(s[back] != '*'){
		back--;
	}
	if(back == front){
		res++;
	}else{
		res += 2;
	}
	int res1 = res;
	int le = front;
	while(1) {
		if(le + k < back) {
			le += k;
			while(s[le] == '.') le--;
			res1++;
		}else{
			break;
		}
	}
	int ri = back;
	int res2 = res;
	while(1) {
		if(ri - k > front) {
			ri -= k;
			while(s[ri] == '.') ri++;
			res2++;
		}else{
			break;
		}
	}
	return min(res1, res2);
}

int main() {
	int t, n, k;
	cin >> t;
	cin.get();
	string s;
	vector<int> res(t);
	for(int i = 0; i < t; i++) {
		cin >> n >> k;
		cin >> s;
		res[i] = f(s, k) ;
	}
	for(int i = 0; i < t; i++) {
		cout << res[i] << endl;
	}
	return 0;
}

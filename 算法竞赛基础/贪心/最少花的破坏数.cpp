#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef struct bull{
	int time;
	int des;
}bull;
bool cmp1(const bull& b1, const bull& b2){//先迁走破坏力强的 
	if(b1.des == b2.des) {
		return b1.time > b2.time;
	}
	return b1.des > b2.des;
}
bool cmp2(const bull& b1, const bull& b2){//先牵走 破坏力/牵走时间 大的 
	return b1.des * 1.0 / b1.time > b2.des * 1.0 / b2.time;
}
int main() {
	int n;
	cin >> n;
	vector<bull> v(n + 1);
	int t, d;
	for(int i = 1; i <= n; i++) {
	 	cin >> t >> d;
	 	v[i].des = d;
	 	v[i].time = t;
	}
	sort(v.begin() + 1, v.end(), cmp2);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++){
			ans += v[j].des * v[i].time * 2;
		}
	}
	cout << ans <<endl;
}
/*
6
3 1
2 5
2 3
3 2
4 1
1 6
*/

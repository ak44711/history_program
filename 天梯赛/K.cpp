#include<iostream>
#include<set>
#include<vector> 
#include<cstdio>
#include<algorithm>
using namespace std;

vector<vector<int> > vv;
int N, M;

int deal(vector<int>& v) {
	set<int> s(v.begin(), v.end());
	return s.size();	
}
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second == p2.second) {
		return vv[p1.first] > vv[p2.first];
	}
	return p1.second > p2.second;
}
void printV(vector<int> & v) {
	for(int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\b\n");
}
int main() {
	
	cin >> N >> M;
	vv.resize(N);
	for(int i = 0; i < N; i++) {
		vv[i].resize(M);
	}
	int t;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &t);
			vv[i][j] = t;
		}
	}
	vector<pair<int, int > >  len(N);
	for(int i = 0; i < N; i++) {
		t = deal(vv[i]);
		len[i].first = i;
		len[i].second = t;
	}
	sort(len.begin(), len.end(),cmp);
	printV(vv[len[0].first]);
	for(int i = 1; i < N; i++) {
		if(vv[len[i - 1].first] != vv[len[i].first]){
			printV(vv[len[i].first]);
		}
	}
	return 0;
}

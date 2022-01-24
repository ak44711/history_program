#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
	int beg;
	int end;
	int cost;
};
int cmp(edge& e1, edge& e2){
	return e1.cost < e2.cost;
}

void mergeRoot(vector<int>& parent, int r1, int r2){
	parent[r2] = r1;
	for(int i = 0; i < parent.size(); i++) {
		if(parent[i] == r2) {
			parent[i] = r1;
		}
	} 
}
int Kruscal(vector<edge>& E, int p, int n) {
	int res = 0;
	vector<int> parent(n);
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int cnt = 0;
	for(int i = 0; i < p; i++) {
		int r1 = parent[E[i].beg];
		int r2 = parent[E[i].end];
		if(r1 != r2){
			res += E[i].cost;
			mergeRoot(parent, r1, r2);
			cnt++;
			if(cnt == n - 1) {
				break;
			}
		}
	}
	return res;
} 
int main() {
	int minx = INT_MAX;
	int n, p;
	cin >> n >> p;
	vector<edge> E(p);
	vector<int> vCost(n);
	int t;
	for(int i = 0; i < n; i++) {
		cin >> t;
		minx = min(minx, t); 
		vCost[i] = t;
	}
	for(int i = 0; i < p; i++) {
		cin >> t;
		E[i].beg = t - 1;
		cin >> t;
		E[i].end = t - 1;
		cin >> t;
		E[i].cost = t * 2 + vCost[E[i].beg] + vCost[E[i].end];
	}
	sort(E.begin(), E.end(), cmp);
	cout << Kruscal(E, p, n) + minx << endl;
	return 0;
} 
/*
5 6
10
10
20
6
30
1 2 5
2 3 5
2 4 12
3 4 17
2 5 15
3 5 6\

10 25
22
4
96
26
33
79
2
2
80
43
2 6 39
1 8 62
1 7 1
2 3 46
1 4 6
3 6 14
9 8 90
6 1 88
7 2 19
2 5 29
4 7 99
4 3 48
5 9 74
3 7 98
4 6 88
1 5 29
10 9 12
2 1 83
8 10 8
7 5 85
8 5 50
6 9 44
8 3 64
6 8 86
5 6 2

*/

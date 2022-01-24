#include<iostream>
#include<queue>
#include<algorithm> 
using namespace std;
void nr_solution(vector<int>& S, vector<int>& K, int r) {
	int pre_min = -1 * INT_MAX, min;
	int idx = 0;
	for(int i = 0; i < S.size(); i++) {
		min = INT_MAX;
		for(int j = 0; j < S.size(); j++) {
			if(S[j] > pre_min && S[j] < min) {
				min = S[j];
			}
		}
		if(i + 1 == K[idx]){
			cout << min << " ";
			idx++;
		}
		pre_min = min;
	}
	cout << endl;
}
void nlogr_solution(vector<int> S, vector<int>& K, int r) {
	sort(S.begin(), S.end());
	for(int i = 0; i < r; i++) {
		cout << S[K[i] - 1] << " ";
	}
	cout << endl;
}
int main() {
	int n;
	cin >> n;
	vector<int> S(n);
	int t;
	for(int i = 0; i < n; i++) {
		cin >> t;
		S[i] = t;
	}
	int r;
	cin >> r;
	vector<int> K(n);
	for(int i = 0; i < r; i++) {
		cin >> t;
		K[i] = t;
	}
	queue<int> que;
	nr_solution(S, K, r);
	nlogr_solution(S, K, r);
	return 0;
}
/*
10
99 22 66 77 44 11 33 55 88 111
3
1 3 4
*/

#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
int n, m;
bool cmp(pair<int, list<int> >& l1, pair<int, list<int> >& l2) {
	return l1.second.size() < l2.second.size();
}
int findMax(vector<pair<int, list<int> > >& relations){
	if(n == 1) return 1;
	vector<int> dp(n, 1); 
	int longest = 1, len;
	for(int i = n - 1; i >= 0; i--) {
		len = relations[i].second.size();
		for(int j = 0; j < len; j++) {
			
		}
	}
	longest = 0;
	for(int i = 0; i < n; i++) {
		longest = max(longest, dp[i]);
	}
	return longest;
}
int main() {
	cin >> n >> m;
	int v1, v2;
	vector<pair<int, list<int> > > relations(n);
	for(int i = 0; i < n; i++) {
		relations[i].first = i;
	}
	for(int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		relations[v1].second.push_back(v2);
		relations[v2].second.push_back(v1);
	}
	sort(relations.begin(), relations.end(), cmp);
 	cout << findMax(relations) << endl;
	return 0;
}

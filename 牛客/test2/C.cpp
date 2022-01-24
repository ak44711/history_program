#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
int n, m;
bool cmp(pair<int, set<int> >& l1, pair<int, set<int> >& l2) {
	return l1.second.size() < l2.second.size();
}
int findMax(vector<pair<int, set<int> > >& relations){
	if(n == 1) return 1;
	vector<int> dp(n, 1); 
	int longest = 1;
    bool flag = false;
	for(int i = n - 2; i >= 0; i--) {
		longest = 1;
        flag = false;
		for(int j = i + 1; j < n; j++) {
			if(relations[i].second.find(relations[j].first) != relations[i].second.end()) {
				longest = max(longest, dp[j]);
                flag = true;
			}
		}
		if(flag == true) dp[i] = longest + 1;
        else dp[i] = 1;
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
	vector<pair<int, set<int> > > relations(n);
	for(int i = 0; i < n; i++) {
		relations[i].first = i;
	}
	for(int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		relations[v1].second.insert(v2);
		relations[v2].second.insert(v1);
	}
	//将关系表按照每个顶点的邻接个数排序 
	sort(relations.begin(), relations.end(), cmp);
 	cout << findMax(relations) << endl;
	return 0;
}

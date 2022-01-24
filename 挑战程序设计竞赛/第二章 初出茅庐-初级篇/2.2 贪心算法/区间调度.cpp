#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int s[maxn];
int t[maxn];
pair<int, int> due[maxn];
int n;
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	for(int i = 0; i < n; i++) {
		due[i].first = s[i];
		due[i].second = t[i];
	}
	sort(due, due + n, cmp);
	int ans = 1;
	int pre = due[0].second;
	printf("%d ", 1);
	for(int i = 1; i < n; i++) {
		if(pre <= due[i].first) {
			ans++;
			pre = due[i].second;
			printf("%d ", i + 1);
		}
	}
	printf("\n%d\n", ans);
	return 0;
}
/*
5
1 2 4 6 8
3 5 7 9 10
*/

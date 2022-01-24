#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	int t;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		v[i] = t;
	}
	int p, x, y;
	int ans = 0;
	for(int i = 0; i < m; i++) {
		cin >> p >> x >> y;
		if(p == 1) {
			v[x] = y;
		}else if(p == 2) {
			ans = 0;
			for(int j = x; j <= y; j++) {
				ans += v[j];
			}
			cout << ans << endl;
		}else{
			ans = - 1 * INT_MAX;
			for(int j = x; j <= y; j++) {
				ans = max(ans, v[j]);
			}
			cout << ans << endl;
		}
	}
	return 0;
}

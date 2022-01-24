#include<iostream>
#define MAX 100090
using namespace std;

int arr[MAX] = {0};
int tree[4 * MAX];

void built(int l, int r, int node){
	if(l == r) {
		tree[node] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	built(l, mid, 2 * node + 1);
	built(mid + 1, r, 2 * node + 2);
	tree[node] = tree[node * 2 + 1] +  tree[node * 2 + 2];
}
void update(int l, int r, int node, int idx, int val) {
	if(l == r) {
		tree[node] = val;
		arr[idx] = val;
		return;
	}
	int mid = (l + r) / 2;
	if(l <= idx && idx <= mid) {
		update(l, mid, node * 2 + 1, idx, val);
	}else {
		update(mid + 1, r, node * 2 + 2, idx, val);
	}
	tree[node] = tree[node * 2 + 1] +  tree[node * 2 + 2];
}

int querySum(int beg, int end, int node, int L, int R) {
	if(beg > R || end < L) {
		return 0;
	}
	if(L <= beg && R >= end) return tree[node];
	if(beg == end) return tree[node];
	int mid = (beg + end) / 2;
	int left_node = 2 * node + 1;
	int right_node = 2 * node + 2;
	int sumL = querySum(beg, mid, left_node, L, R);
	int sumR = querySum(mid + 1, end, right_node, L, R);
	return sumL + sumR;
}
int query(int L, int R) {
	int maxn = -INT_MAX;
	for(int i = L; i <= R; i++) {
		maxn = max(maxn, arr[i]);
	}
	return maxn;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	built(0, n - 1, 0);
	int p, x, y;
	long ans;
	for(int i = 0; i < m; i++) {
		cin >> p >> x >> y;
		if(p == 1) {
			update(0, n - 1, 0, x - 1, y);
		}else if(p == 2) {
			cout << querySum(0, n - 1, 0, x - 1, y - 1) << endl;
		}else{
			ans = - 1 * INT_MAX;
			for(int j = x - 1; j <= y - 1; j++) {
				ans = max(ans, (long)arr[j]);
			}
			cout << ans << endl;
		}
	}
	return 0;
}

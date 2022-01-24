#include<iostream>
using namespace std;
int num[1010] = {0};
int t[1014] = {0};
int lowbit(int x) {
	return x &(-x);
}
void add(int idx, int p) {
	while(idx < 1010) {
		t[idx] += p;
		idx += lowbit(idx);
		/*idx::129
		1000 0001
		1000 0010
		1000 0100
		1000 1000
		1001 0000
		1010 0000
		1100 0000
	   10000 0000
	  100000 0000
	 1000000 0000
	10000000 0000
		*/
	}
}
int sum(int k) {//前k项和 
	int ans = 0;
	while(k > 0) {
		ans += t[k];
		k -= lowbit(k);
		/*k 255
		1111 1111
		1111 1110
		1111 1100
		1111 1000
		1111 0000
		1110 0000
		1100 0000
		1000 1000
		0000 0000
		*/
	}
	return ans;
}
int query(int beg, int end) {//查询区间[beg, end]的 内容 
	return sum(end) - sum(beg - 1);
}
int main()  {
	int n = 20;
	//cin >> n;
	for(int i = 1; i <= n; i++) {
		//cin >> num[i];
		num[i] = i;
		add(i, num[i]);
	}
	for(int i = 1; i <= n; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
	cout << query(8,8) << endl;
	return 0;
}

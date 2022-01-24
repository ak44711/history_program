#include<iostream>
#include<vector>
using namespace std;
int  ordered_find(vector<int>& L, int x){
	int j = 0;
	int n = L.size();
	while(j < n && x > L[j]) {
		j++;
	}
	if(j > n - 1 || x < L[j]) {
		j =  -1;
	}
	return j;
}
int main() {
	int n = 10;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		arr[i] = (i + 1) * (i + 1);
	}
	int x = 5;
	int res = ordered_find(arr, x);
	if(res == -1) {
		cout << "δ�ҵ�" << endl;
	}else{
		cout << x << "��λ���ڵ�" << res + 1 << endl;
	}
	x = 9;
	res = ordered_find(arr, x);
	if(res == -1) {
		cout << "������δ�ҵ�" << x << endl;
	}else{
		cout << x << "��λ���ǣ� " << res + 1 << endl;
	}
	return 0;
}

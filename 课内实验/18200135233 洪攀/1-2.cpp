#include<iostream>
#include<vector>
using namespace std;
//排序数组并且统计交换顺序 
int mysort(vector<int> A) {
	int size = A.size();
	int swapTimes = 0; 
	for(int i = 0; i < size - 1; i++) {
		for(int j = i + 1; j < size; j++) {
			if(A[j] < A[i]) {
				swap(A[i], A[j]);
				swapTimes++;
			}
		}
	}
	return swapTimes;
}
//枚举数组所有可能的排列情况并对每个数组进行排序统计交换次数 
void dfs(vector<int>& v, int first, int len) {
	if(len == first) {
		for(int i = 0; i < len; i++) {
			cout << v[i] << " ";
		}
		cout<< "该数组交换次数为" << mysort(v) << endl;
		return;
	}
	for(int i = first; i < len; i++) {
		swap(v[first], v[i]);
		dfs(v, first + 1, len);
		swap(v[first], v[i]);
	}
}

int main(){
	int n = 5;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		v[i] = i + 1;
	}
	dfs(v, 0, n);
	return 0;
} 

#include<iostream>
#include<vector>
using namespace std;
//数组全排列， 测试每一种情况 
void dfs(vector<int>& v, int first, int len) {
	if(len == first) {
		for(int i = 0; i < len; i++) {
			cout << v[i] << " ";
		}
		//只需选出前三个数，选出中位数，中位数计算方法为三个数总和减去最大和最小的数 
		cout<< "该数组中的一个非最大最小的数为：" << v[0] + v[1] + v[2] - max(max(v[0], v[1]), v[2]) - min(min(v[0], v[1]), v[2])<< endl;
		return;
	}
	for(int i = first; i < len; i++) {
		swap(v[first], v[i]);
		dfs(v, first + 1, len);
		swap(v[first], v[i]);
	}
}

int main(){
	int n = 4;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		v[i] = i + 1;
	}
	dfs(v, 0, n);
	return 0;
} 

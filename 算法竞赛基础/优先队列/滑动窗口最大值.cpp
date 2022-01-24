#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int t;
	vector<int> arr(n);
	vector<int> res;
	for(int i = 0; i < n; i++) {
		cin >> t;
		arr[i] = t;
	}
	deque< pair<int, int> > deq;//value, index
	int i = 0;
	int j = 0;
	//初始化一个窗口为k的滑动窗口，并且将范围内的内容放进单调队列 
	for( ; j < k; j++) {
		while(!deq.empty() && deq.back().first <= arr[j]) deq.pop_back();
		deq.push_back(make_pair(arr[j], j));
	}
	cout << i << " " << j << endl;
	res.push_back(deq.front().first);
	while(j < n) {
		while(!deq.empty() && deq.back().first <= arr[j]) deq.pop_back();//将队列尾部小于等于arr[j]的内容出队 
		deq.push_back(make_pair(arr[j], j));//arr[j]入队 
		i++; 
		j++;
		while(!deq.empty() && deq.front().second < i) deq.pop_front();//将队首不在当前窗口范围的内容出队 
		res.push_back(deq.front().first);//此时队首为最大值，因此记录队首元素作为结果 
		
	}
	for(int m = 0; m < n - 2; m++) {
		cout << res[m] << " ";
	}
	cout << endl;
	return 0;
} 
/*
14 3
1 3 -1 -3 5 3 6 7 1 2 3 4 5 4 
*/

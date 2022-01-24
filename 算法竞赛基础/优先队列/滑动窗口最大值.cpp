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
	//��ʼ��һ������Ϊk�Ļ������ڣ����ҽ���Χ�ڵ����ݷŽ��������� 
	for( ; j < k; j++) {
		while(!deq.empty() && deq.back().first <= arr[j]) deq.pop_back();
		deq.push_back(make_pair(arr[j], j));
	}
	cout << i << " " << j << endl;
	res.push_back(deq.front().first);
	while(j < n) {
		while(!deq.empty() && deq.back().first <= arr[j]) deq.pop_back();//������β��С�ڵ���arr[j]�����ݳ��� 
		deq.push_back(make_pair(arr[j], j));//arr[j]��� 
		i++; 
		j++;
		while(!deq.empty() && deq.front().second < i) deq.pop_front();//�����ײ��ڵ�ǰ���ڷ�Χ�����ݳ��� 
		res.push_back(deq.front().first);//��ʱ����Ϊ���ֵ����˼�¼����Ԫ����Ϊ��� 
		
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

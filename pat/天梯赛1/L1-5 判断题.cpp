#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m; 
	cin >> n >> m;
	//��ĿȨ�� 
	int weigh;
	vector<int> weight(m);
	for(int i = 0; i < m; i++) {
		cin >> weigh;
		weight[i] = weigh;
	}
	//��Ŀ�� 
	vector<bool> answer(m);
	bool t;
	for(int i = 0; i < m; i++) {
		cin >> t;
		answer[i] = t;
	}
	
	//ѧ���÷� 
	int earn = 0;
	vector<int> score(n);
	for(int i = 0; i < n; i++) {
		earn = 0;
		for(int j = 0; j < m; j++) {
			cin >> t;
			if(answer[j] == t){
				earn += weight[j];
			}
		}
		score[i] = earn;
	}
	for(int i = 0; i < n; i++) {
		cout << score[i] << endl;
	}
	return 0;
} 

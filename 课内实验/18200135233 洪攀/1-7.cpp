#include<iostream>
#include<vector>
using namespace std;

int find_second_min(vector<int>& S, int n) {
	int mini = 0;
	int SecondMin = 0;
	mini = min(S[0], S[1]);
	SecondMin = max(S[0], S[1]);
	for(int i = 2; i < n; i ++ ) {
		if(S[i] < SecondMin){
			if(S[i] < mini) {
				SecondMin = mini;
				mini = S[i];
			}else{
				SecondMin = S[i];
			}
		}
	}
	return SecondMin;
}

int main(){
	int n;
	cout << "��������Ҫ¼������ĸ���: " << endl; 
	cin >> n;
	vector<int> v(n);
	cout << "��ֱ�¼����n����" << endl;
	int t;
	for(int i = 0; i < n; i++) {
		cin >> t;
		v[i] = t;
	} 
	cout << "�ڶ�С����Ϊ�� " << find_second_min(v, v.size());
	return 0;
} 

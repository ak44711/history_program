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
	cout << "请输入需要录入的数的个数: " << endl; 
	cin >> n;
	vector<int> v(n);
	cout << "请分别录入这n个数" << endl;
	int t;
	for(int i = 0; i < n; i++) {
		cin >> t;
		v[i] = t;
	} 
	cout << "第二小的数为： " << find_second_min(v, v.size());
	return 0;
} 

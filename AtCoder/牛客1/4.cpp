#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<bool> v(201, false);
	int n;
	cin >> n;
	int t, max = 0;
	for(int i = 0; i < n; i++) {
		cin >> t;
		v[t] = true;
		if(t > max) {
			max = t;
		}
	}
	bool flag = false;
	for(int i = 1; i <= max; i++) {
		if(v[i] == false) {
			flag = true;
			printf("%d\n", i);
		}
	}
	if(!flag) {
		cout << "good job" << endl;
	}
	return 0;
}

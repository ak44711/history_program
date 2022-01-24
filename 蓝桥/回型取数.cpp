#include<iostream>
#include<vector>

using namespace std;
int main() {
	int m = 0, n = 0;
	cin >> m >> n;
	vector<vector<int> > vv(m, vector<int>(n) );
	vector<vector<bool> > mark(m, vector<bool>(n, false) );
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> vv[i][j];
		}
	}
	
	int i = -1, j = 0;
	int turn_times = 0;
	while(turn_times < 2) {
		turn_times++;
		while(i < m - 1 && mark[i + 1][j] == false){
			turn_times = 1;	
			i++;
			cout << vv[i][j] << " ";
			mark[i][j] = true;
		}
		turn_times++;
		while(j < n - 1 && mark[i][j + 1] == false){
			turn_times = 1;	
			j++;
			cout << vv[i][j] << " ";
			mark[i][j] = true;
		}
		turn_times++;
		while(i > 0 && mark[i - 1][j] == false){
			turn_times = 1;	
			i--;
			cout << vv[i][j] << " ";
			mark[i][j] = true;
		}
		turn_times++;
		while(j > 0 && mark[i][j - 1] == false){
			turn_times = 1;	
			j--;
			cout << vv[i][j] << " ";
			mark[i][j] = true;
		}
	}
	return 0;
}

#include<iostream>

using namespace std;

int main(){
	bool arr[101][101] = {false};
	int n;
	cin >> n;
	int x1, y1;
	int x2, y2;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = x1; j < x2; j++){
			for(int k = y1; k < y2; k++){
				arr[j][k] = true;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			if(arr[i][j] == true){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

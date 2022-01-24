#include<iostream>
using namespace std; 
int happiness[] = {1,5,10,6,7};
int car[] = {1,3,3,8, 5};
int len = 5;
int happ = 6;
int bag2dp() {
	int arr[len + 1][happ + 1];
	for(int i = 0; i < len + 1; i++) {
		arr[i][0] = 0;
	}
	for(int i = 0; i < happ + 1; i++) {
		arr[0][i] = 0;
	}
	for(int j = 1; j <= happ; j++) {
		for(int i = 1; i <= len; i++) {
			if(j < car[i]) {
				arr[i][j] = arr[i - 1][j];
			}else{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - car[i]] + happiness[i]);
			}
		}
	}
	for(int i = 0; i <= len; i++) {
		for(int j = 0; j <= happ; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return arr[len][happ];
}
int main() {
	cout << bag2dp() << endl;
	return 0;
}

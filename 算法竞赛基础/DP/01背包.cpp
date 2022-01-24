#include<iostream>
#include<string.h>
using namespace std;
int price[] = {1,2,3,4,5};
int v[] = {5,4,3,2,1};
int bag = 10;
int dp2D() {
	int row = sizeof(price) / sizeof(price[0]);	
	int arr[row + 1][bag +1] ;
	for(int i = 0; i <= bag; i++) {
		arr[0][i] = 0;
	}
	for(int i = 0; i <= row; i++) {
		arr[i][0] = 0;
	}
	for(int i = 1;  i <= row; i++) {
		for(int j = 1; j <= bag; j++) {
			if(v[i] > j){
				arr[i][j] = arr[i - 1][j];
			}else{
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - v[i - 1]] + price[i - 1]) ;
			}
		}
	}
	for(int i = 0;  i <= row; i++) {
		for(int j = 0; j <= bag; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return arr[row][bag];
}
int dp1D(){
	int row = sizeof(price) / sizeof(price[0]);	
	int arr[bag + 1] = {0};
	for(int i = 1; i <= row; i++) {
		for(int j = bag; j > 0; j--) {
			if(v[i] <= j) {
				arr[j] = max(arr[j], arr[j - v[i - 1]] + price[i - 1]);
			}
		}
		for(int k = 0; k <= bag; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
	return arr[bag];
}
int main() {
	cout << dp2D() << endl << endl;
	cout << dp1D() << endl;
	return 0;
} /*
		1	2	3	4	5	6	7	8	9	10
	0	0	0	0	0	0	0	0	0	0	0
1	0	0	0	0	0	1	1	1	1	1	1
2	0	0	0	0	2	2	2	2	2	3	3
3	0	0	0	3	3	3	3	5	5	5	5
4	0	0	4	4	4	7	7	7	7	9	9
5	0	5	5	9	9	9	12	12	12	12	14

*/

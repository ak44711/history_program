#include<iostream>
using namespace std;
int maxSubSum(int* a, int len) {
	int arr[len] = {a[0]};
	int maxium = arr[0]; 
	for(int i = 1; i < len; i++) {
		arr[i] = max(arr[i - 1] + a[i], a[i]);
		if(maxium < arr[i]) {
			maxium = arr[i];
		}
		for(int j = 0; j < len; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	return maxium;
}
int main() {
	int arr[] = {-2, 11, -4, 13, -5, -2};
	//int arr[] = {1};
	int len = sizeof(arr) / sizeof(int);
	int i = 0, j = 0; 
	int sum = 0, max = arr[0];
	while(j < len) {
		sum += arr[j];
		if(sum > max) {
			max = sum;
		}
		if(sum < 0) {
			sum = 0;
			i = j + 1;
		}
		cout << sum << " ";
		j++;
	}
	cout << max << endl;
	cout << maxSubSum(arr, len) << endl;
	return 0; 
} 

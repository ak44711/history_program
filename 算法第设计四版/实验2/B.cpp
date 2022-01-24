#include<iostream>
#include<vector>
using namespace std;

int find_peak(vector<int>& arr, int le, int ri){
	int mid = le + (ri - le) / 2;
	if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;
	if(arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
		return find_peak(arr, mid + 1, ri);
	if(arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
		return find_peak(arr, le, mid - 1);
}

int main() {
	vector<int> arr = {1,2,3,4,5,6,5,4,3,2,1};
	cout << arr[find_peak(arr, 0, arr.size())] << endl;
	return 0;
} 

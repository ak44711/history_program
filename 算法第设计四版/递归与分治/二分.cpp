#include<iostream>
#include<vector>
using namespace std;
int bin_search(vector<int>& arr, int x) {
	int le = 0;
	int ri = arr.size() - 2;
	while(le <= ri) {
		int mid = le + (ri - le) / 2;
		if(x == arr[mid]) return mid;
		if(x > arr[mid]) {
			le = mid + 1;
		}else {
			ri = mid - 1;
		}
	}
	return -1;
} 
int main () {
	vector<int> arr = {1,2,3,4,5,6,7,7,8};
	cout <<  bin_search(arr, 3) << endl;
	cout <<  bin_search(arr, -7) << endl;
	return 0;
}

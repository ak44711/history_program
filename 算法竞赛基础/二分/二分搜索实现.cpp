#include<iostream>
using namespace std;
typedef int pos;
pos binSearch(int arr[], int beg, int end, int val) {
	int mid = beg + (end - beg) / 2;
	while(beg <= end) {
		if(arr[mid] == val) {
			return mid;
		}else if(arr[mid] < val) {
			beg = mid + 1;
		}else{
			end = mid - 1;
		}
		mid = beg + (end - beg) / 2;
	}
	return -1;
}

pos upper_bound(int arr[], int beg, int end, int val) {
	pos p = binSearch(arr, beg, end, val);
	if(p == -1) {
		return -1;
	}
	while(p != end - 1 && arr[p] != arr[++p]);
	if()
}
int main() {
	int arr[] = {0,1,2,3,4,4,4,4,5,6,7,8,9,10};
	int p = binSearch(arr, 0, sizeof(arr) / sizeof(int), 5);
	cout << p << endl;
}

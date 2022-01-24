#include<iostream>
#include<vector>
using namespace std;

int bin_find(vector<int>& arr, int val, int le, int ri) {
	if(val <= arr[le]) return le;
	if(val >= arr[ri]) return ri + 1;
	int mid = le + (ri - le) / 2;
	if(val == arr[mid]) return mid;
	if(val > arr[mid]) return bin_find(arr, val, mid + 1, ri);
	if(val < arr[mid]) return bin_find(arr, val, le, mid - 1);
}
void insert_sort(vector<int>& arr) {
	int val;
	for(int i = 1; i < arr.size(); i++) {
		val = arr[i];
		int pos = bin_find(arr, val, 0, i - 1);
		for(int j = i; j > pos; j--){
			arr[j] = arr[j - 1];
		}
		arr[pos] = val;
	}
}
int main() {
	vector<int> arr = {6,34,6,7,34,7,847,267,757,5};
	for(int i : arr) {
		cout << i << " ";
	}
	cout << endl;
	insert_sort(arr);
	for(int i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

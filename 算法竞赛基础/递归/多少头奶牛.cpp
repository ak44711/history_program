#include<iostream>
#include<vector>
using namespace std;

int count(int y) {
	int n1 = 0, n2 = 1, n3 = 0, n4 = 0;
	for(int i = 1; i <= y; i++) {
		n4 += n3;
		n3 = n2;
		n2 = n1;
		n1 = n4;
	}
	return n1 + n2 + n3 + n4;
} 

int main() {
	int n;
	vector<int> arr;
	while((cin>>n) && n != 0) {
		arr.push_back(n);
	}
	for(int i = 0; i < arr.size(); i++) {
		cout << count(arr[i]) << endl;
	}
	return 0;
}

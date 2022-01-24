#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3(10, 7);
	vector<int> v4(15);
	vector<int> v5{1,2,3,4,5,6,7,8,9,0};
	vector<int> v6{1,2,3,4,5,6,7,8,9,0};
	
	v2 = v6;
	v6.clear();
	
	for(int i = 0; i < v1.size(); i++){
		cout << v1[i] << ' ';
	}
	cout << endl;
	
	for(int i = 0; i < v2.size(); i++){
		cout << v2[i] << ' ';
	}
	cout << endl;
	
	for(int i = 0; i < v3.size(); i++){
		cout << v3[i] << ' ';
	}
	cout << endl;
	
	for(int i = 0; i < v4.size(); i++){
		cout << v4[i] << ' ';
	}
	cout << endl;
	
	for(int i = 0; i < v5.size(); i++){
		cout << v5[i] << ' ';
	}
	cout << endl;
	
	for(int i = 0; i < v6.size(); i++){
		cout << v6[i] << ' ';
	}
	cout << endl;
	return 0;
}

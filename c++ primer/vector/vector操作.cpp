#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
	vector<int> v1;
	list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	
	
	
	
	
	
	
	
	
	
	
	for(int i = 0; i < 20; i++){
		v1.push_back(i);
	}
	for(int i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	cout << endl;
	for(int &i : v1){
		i *= i;
	}
	
	for(int i : v1){
		cout << i << " ";
	}
	
	return 0;
} 

#include<iostream>
#include<vector> 
using namespace std;

int main(){
	int L, M;
	cin >> L >> M;
	
	vector<int> begins;
	vector<int> ends;
	//L + 1���� 
	vector<bool> tree(L + 1,true);
	
	int t; 
	for(int i = 0; i < M; i++){
		cin >> t;
		begins.push_back(t);
		cin >> t;
		ends.push_back(t);
	}
	
	//�������� 
	for(int i = 0; i < M; i++){
		for(int j = begins[i]; j <= ends[i]; j++){
			tree[j] = false;
		}
	}
	
	//ͳ����������
	int count = 0;
	for(int i = 0; i < tree.size(); i++){
		if(tree[i] == true){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}



#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
const int N = 1e6;

vector<int> A;
vector<int> B;
vector<int> C;


void ebb() {
	int t = 0;
	while(A.size() < B.size()) A.push_back(0);
	while(A.size() > B.size()) B.push_back(0);
	
	for(int i = 0; i < A.size(); i++) {
	    if(A[i] < B[i] + t){
		    C.push_back(A[i] - B[i] - t + 10);
		    t = 1;
	    }else{
	        C.push_back(A[i] - B[i] - t);
	        t = 0;
	    }
	}
}



int main() {
	string input1, input2;
	
	cin >> input1;
	cin >> input2;
	string symbol;
	//确保被减数大
	if(input1 < input2) {
	    swap(input1, input2);
	    symbol = "-";
	}
	
	for(int i = input1.size() - 1; i >= 0; i--) A.push_back(input1[i] - '0');
	
	for(int i = input2.size() - 1; i >= 0; i--) B.push_back(input2[i] - '0');
	 
	ebb();
	
	cout << symbol;
	int j = C.size() - 1;
	while(C[j] == 0) j--;
	if(j <= 0) cout << C[0];
	else {
		while(j >= 0) cout << C[j--];
	}
	cout << endl;
	
}

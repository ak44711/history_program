#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int N, M, Smax;
	cin >> N >> M >> Smax;
	int op;
	vector<string> rails(N);
	vector<int> idxs(N, 0);
	string ans;
	
	string t;
	for(int i = 0; i < N; i++) {
		cin >> t;
		rails[i] = t;
	}
	
	stack<char> stk;
	
	scanf("%d", &op);
	while(op != -1) {
		
		if(op == 0) {
			if(!stk.empty()) {
				ans.push_back(stk.top());
				stk.pop();
			}
		}else{
			if(idxs[op - 1] == M);
			else {
				if(stk.size() == Smax) {//Èç¹ûÂúÁË 
					ans.push_back(stk.top());
					stk.pop();
				}
				stk.push(rails[op-1][idxs[op - 1]]);
				idxs[op - 1]++; 
			}
		}
		scanf("%d", &op);
	}
	cout << ans << endl;
	return 0;
}

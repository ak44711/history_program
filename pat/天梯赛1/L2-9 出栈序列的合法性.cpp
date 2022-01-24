#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool isVaild(vector<int>& seq, int M, int N) {
	int next = 1;
	stack<int> stk;
	int i = 0;
	while(i < N){
		if(stk.empty() || stk.top() < seq[i]) {
			stk.push(next);
			next++;
			if(stk.size() > M) return false;
 		}else if(stk.top() == seq[i]) {
 			i++;
 			stk.pop();
		}else{
			return false;
		}
	}
	return i==N;
} 
int main() {
	int M, N, K, t;
	cin >> M >> N >>  K;
	vector<int> seq(N);
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < N; j++) {
			cin >> t;
			seq[j] = t;
		}
		if(isVaild(seq, M, N)){
			cout <<"YES" << endl;
		}else{
			cout <<"NO" << endl;
		}
	}
	return 0;
}

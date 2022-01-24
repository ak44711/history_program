#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	map<int,queue<int> > mq;
	set<int> res;
	int beg, end;
	for(int i = 0; i < m; i++){
		cin >> beg >> end;
		mq[beg - 1].push(end - 1);
	}
	queue<int> q;
	q.push(0);
	int t = 0;
	while(!q.empty()){
		t = q.front() ;
		while(!mq[t].empty()){
			q.push(mq[t].front());
			mq[t].pop();
		}
		res.insert(q.front());
		q.pop();
	}
	
	for(set<int>::iterator it = res.begin(); it != res.end(); it++){
		cout << *it + 1<< " ";
	}
	cout << endl;
	return 0;
}

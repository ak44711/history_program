#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct info{
	int income;
	int outcome;
	int cnt;
	info() {
		income = 0;
		cnt = 0;
	}
};
bool cmp(pair<int, info>& p1, pair<int, info>& p2) {
	if(p1.second.income == p2.second.income){
		if(p1.second.cnt == p2.second.cnt) {
			return p1.first < p2.first;
		}
		return p1.second.cnt > p2.second.cnt;
	}
	return p1.second.income > p2.second.income;
}
int main() {
	int K, N;
	cin >> N;
	vector<pair<int, info> > people(N);
	int id, money, sum;
	for(int i = 0; i < N; i++) {
		people[i].first = i + 1;
	} 
	for(int i = 0; i < N; i++) {
		sum = 0;
		cin >> K;
		for(int j = 0; j < K; j++) {
			cin >> id >> money;
			sum += money;
			people[id - 1].second.income += money;
			people[id - 1].second.cnt ++;
		}
		people[i].second.income -= sum;
	}
	sort(people.begin(), people.end(), cmp);
	for(int i = 0; i < N; i++) {
		printf("%d %.2f\n", people[i].first, people[i].second.income * 1.0 / 100);
	}
	return 0;
}

#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<string>
using namespace std;
string hero;
string boss;

vector<pair<string, int> > path;
vector<pair<string, int> > bestPath;
map<string, int> enemy;
map<string, list<pair, int>> maps;

void dfs() {
	
} 

int main() {
	int N, M;
	cin >> N >> M;
	cin >> hero >> boss;
	string name;
	int num;
	for(int i = 0; i < N; i ++) {
		cin >> name >> num;
		enemy[name] = num;
	}
	string s;
	int cost;
	for(int i = 0; i < M; i++) {
		cin >> name >> s >> cost;
		map[name].insert(make_pair(s, cost));
	}
	
	return 0;
}

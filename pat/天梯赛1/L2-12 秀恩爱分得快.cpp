#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
using  psf= pair<string, float>;
struct x {
	string s;
};
bool operator == (const psf & l, const x & r) {
	return l.first == r.s;
}
int main () {
	int N, M;
	cin >> N >> M;
	int num;
	string t;
	vector<set<string> > pictures(M); 
	for(int i = 0; i < M; i++) { // 保存照片信息 
		cin >> num;
		for(int j = 0; j < num; j++) {
			cin >> t;
			pictures[i].insert(t);
		}
	}
	string a, b;
	cin >> a >> b;//约好去爬山的男女
	map<string, float> friends;
	float weigh = 0;
	int len = 0;
	cout << endl;
	for(int i = 0; i < M; i++) { 
		weigh = 1.0 / pictures[i].size();
		if(pictures[i].find(a) != pictures[i].end()) {
			len = a.size();
			for(auto it = pictures[i].begin(); it != pictures[i].end(); it++) {
				if(it ->size() == 3 - len) {
					friends[*it] += weigh;
				}
			}
		}
		if(pictures[i].find(b) != pictures[i].end()) {
			len = b.size();
			for(auto it = pictures[i].begin(); it != pictures[i].end(); it++) {
				if(it ->size() == 3 - len) {
					friends[*it] += weigh;
				}
			}
		}
	}
	vector<pair<string, float> > male;
	vector<pair<string, float> > female;
	auto it = friends.begin();
	while(it ->first.size() == 2) {
		if(female.empty() || female.back().second == it ->second) {
			female.push_back(make_pair(it ->first, it ->second));
		}else if(female.back().second < it ->second) {
			while(!female.empty() && female.back().second < it ->second) {
				female.pop_back();
			}
			female.push_back(make_pair(it ->first, it ->second));
		}
		it++;
	}
	while(it != friends.end() && it->first.size() == 1) {
		if(male.empty() || male.back().second == it ->second) {
			male.push_back(make_pair(it ->first, it ->second));
		}else if(male.back().second < it ->second) {
			while(!male.empty() && male.back().second < it ->second) {
				male.pop_back();
			}
			male.push_back(make_pair(it ->first, it ->second));
		}
		it++;
	}
	
	if(a.size() == 2) {//a女b男 
		cout << "a nv b nan " << endl;
		if(find(male.begin(), male.end(), x{b}) != male.end()
			&& find(female.begin(), female.end(), x{a}) != female.end()) {//天生一堆 
			cout << a << " " << b; 
		}else{//一人出轨，找出小三 
			if(find(male.begin(), male.end(), x{b}) != male.end()) {//a没出轨 
				cout << a << " " << b << endl;
			}else{//a出轨
				for(int i = 0; i < male.size(); i++) { 
					cout << a << " " << male[i].first << endl;
				}
			}
			if(find(female.begin(), female.end(), x{a}) != female.end()) {//b没出轨 
				cout << b << " " << a << endl;
			}else{//b出轨
				for(int i = 0; i < female.size(); i++) { 
					cout << b << " " << female[i].first << endl;
				}
			}
		}
	}else{//a男b女
		cout << "a nan b nv" << endl;
		if(find(female.begin(), female.end(), x{b}) != female.end() && find(male.begin(), male.end(), x{a}) != male.end()) {//天生一堆 
			cout << a << " " << b; 
		}else{//有人出轨，找出小三 
			if(find(female.begin(), female.end(), x{b}) != female.end()) {//a没出轨 
				cout << a << " " << b << endl;
			}else{//a出轨
				for(int i = 0; i < female.size(); i++) { 
					cout << a << " " << female[i].first << endl;
				}
			}
			if(find(male.begin(), male.end(), x{a}) != male.end()) {//b没出轨 
				cout << b << " " << a << endl;
			}else{//a出轨
				for(int i = 0; i < male.size(); i++) { 
					cout << b << " " << female[i].first << endl;
				}
			}
		}
	}
	return 0;
}

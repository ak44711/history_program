#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {
	int t, id, hour, minute;
	char key, temp;
	int cnt = 0, p = 0;
	cin >> t;
	int time[1030] = {0};
	int people[t] = {0};
	bool isborrow[1030] = {0};
	for(int i = 0; i < t; ) {
		cin >> id >> key >> hour >> temp >> minute;
		if(id == 0) {
			if(p != 0) {
				cout << p << " " << (int)(1.0 * cnt / p + 0.5) << endl;
			}else{
				cout << "0 0" << endl; 
			}
			memset(isborrow, 0, sizeof(isborrow));
			memset(time, 0, sizeof(time));
			i++;
			cnt = 0;
			p = 0;
		}else if(key == 'S') {
			isborrow[id] = true;
			time[id] = hour * 60 + minute;
		}else if(key == 'E'){
			if(isborrow[id]) {
				isborrow[id] = false;
				cnt += hour * 60 + minute- time[id];
				p++;
			}
		}
	}
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int main () {
	int m, n;
	cin >> m >> n;
	string machine;
	string player;
	cin >> machine;
	cin >> player;
	int r1 = 0, p1 = 0, s1 = 0; 
	int r2 = 0, p2 = 0, s2 = 0;
	int le = 0, ri = 0;
	for(ri = 0; ri < player.size(); ri++) {
		if(machine[ri] == 'R') r1 ++;
		else if(machine[ri] == 'S') s1++;
		else p1++;
		if(player[ri] == 'R') r2++;
		else if(player[ri] == 'P') p2++;
		else s2++;
	}
	int maxScore = min(r1, p2) + min(p1, s2) + min(s1, r2);
	while(ri < machine.size()) {
		if(machine[ri] == 'R') r1 ++;
		else if(machine[ri] == 'S') s1++;
		else p1++;
		if(machine[le] == 'R') r1 --;
		else if(machine[le] == 'S') s1--;
		else p1--;
		maxScore = max(min(r1, p2) + min(p1, s2) + min(s1, r2), maxScore);
		ri++;
		le++;
	}
	cout << maxScore << endl;
	return 0;
}

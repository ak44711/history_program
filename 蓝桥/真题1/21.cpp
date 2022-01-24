#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main() {
	list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	for(int i : ls) {
		cout << i << " ";
	}
	cout << endl;
	reverse(ls.begin(), ls.end());
	for(int i : ls) {
		cout << i << " ";
	}
	cout << endl;
} 

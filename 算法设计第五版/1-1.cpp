#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
void write(ostream& os, int num) {
	os << num << endl; 
}
int main() {
	int t, n;
	int count[10] = {0};
	ifstream ins("input.txt");
	ofstream os("output.txt");
	string s;
	getline(ins, s);
	n = atoi(s.c_str());
	for(int i = 0; i <= n; i++) {
		t = i;
		while(t > 0) {
			count[t % 10] += 1;
			t /= 10;
		}
	}
	for(int i = 0; i < 10; i++) {
		write(cout, count[i]);
		write(os, count[i]);
	}
	return 0;
}

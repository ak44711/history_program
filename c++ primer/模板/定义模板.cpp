#include<iostream>
using namespace std;
template <typename T>
int cmp(const T &v1, const T &v2) {
	if(v1 < v2) return -1;
	if(v2 < v1) return 1;
	return 0;
}
int main() {
	string s1 = "df";
	string s2 = "fss";
	cout << cmp(s1, s2) << endl;
	return 0;
} 

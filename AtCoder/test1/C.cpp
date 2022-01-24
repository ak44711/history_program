#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	auto it = find(s.begin(), s.end(), '.');
	cout << s.substr(0, it - s.begin());
	return 0;
}

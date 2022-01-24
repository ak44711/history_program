#include<iostream>
#include<algorithm>
#include<string>
using namespace std; 
using  psf= pair<string, float>;
struct x {
	string s;
};
bool operator == (const psf & l, const x & r) {
	return l.first == r.s;
}
bool cmp(psf& v1, string s) {
	return v1.first == s;
}
int main() {
	vector<pair<string, float>> vsf = {
		{"sss",1.0},{"aaa",2.0},{"ddd",3.0}
	};
	string b = "sss";
	auto it = find(vsf.begin(), vsf.end(), x{b});
	 cout << it->first << " " << it->second;
	return 0;
}
/*
using  psf= pair<string, float>;
struct x {
	string s;
};
bool operator == (const psf & l, const x & r) {
	return l.first == r.s;
}
int main() {
	vector<pair<string, float>> vsf = {
		{"sss",1.0},{"aaa",2.0},{"ddd",3.0}
	};
	auto it = find(vsf.begin(), vsf.end(), x{"sss"});
	 cout << it->first << " " << it->second;
	return 0;
}*/

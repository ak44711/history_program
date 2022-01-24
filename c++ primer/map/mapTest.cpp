#include<iostream>
#include<map>
#include<boost/unordered_map>
using namespace std;
using boost;

struct info{
        int beg = 1;
        int last = 1;
        int count = 1;
    };

int main() {
	boost::unordered_map<int, struct info> m;
	struct info temp;
	m[1] = temp;
	m[2] = temp;
	m.find(1);
	m[1].beg++;
	cout << m[1].beg << endl;
	cout << m[2].beg << endl;
	return 0;
} 

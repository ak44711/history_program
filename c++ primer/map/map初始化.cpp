#include<map>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	//初始化map和set 
	map<string, size_t> word_count;
	
	set<string> exclude = 	{"The","But", "And", "Or", "An","A",
						   	"the", "but", "and", "or", "an", "a"};
						   	
	map<string, string> authors = { {"joyce", "James"},
									{"Austen", "Jane"},
									{"Dichens", "Charles"}}; 
	
	//初始化multimap或multiset
	vector<int> ivec;
	for(vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;
	return 0;
}

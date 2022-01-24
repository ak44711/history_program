#include<utility>
#include<iostream> 
#include<vector>
using namespace std;

int main() {
	pair<string, string> anon;
	pair<string, string> author("james", "jocye");
	pair<string, size_t> word_count = {"helloworld", 1};
	
	pair<string, vector<int>> line;
	
	cout << author.first << " " << author.second << endl;
	cout << word_count.first << " " << word_count.second << endl;
	return 0;
}

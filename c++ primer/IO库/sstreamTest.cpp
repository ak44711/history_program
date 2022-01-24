#include<iostream>
#include<sstream> 
#include<vector>
using namespace std;
struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string line, word;
	vector<PersonInfo> people;
	while(getline(cin, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while(record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	for(int i = 0; i < people.size(); i++) {
		cout << people[i].name << " ";
		for(int j = 0; j < people[i].phones.size(); j++) {
			cout << people[i].phones[j] << " ";
		}
		cout << endl;
	}
	for(const auto& entry : people) {
		ostringstream formatted, badNums;
		for(const auto& nums : entry.phones) {
			if(!valid(num)) {
				badNums << " " << format(nums);
			}else
				formatted << " " << format(nums);
		}
		if(badNums.str().empty() ) {
			os << entry.name << " " << formatted.str() << endl;
		}else{			
			cerr << "input error: " << entry.name << "invalid number(s)" << badNUms.str() << endl;
		}
	}
	return 0;
}
/*
margan 2015552368 8625550123
drew 9735550130
lee 6095550123 2015550175 800555000
*/

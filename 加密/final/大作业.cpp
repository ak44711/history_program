#include<iostream>
#include<fstream>
using namespace std;

void insert_item(string id, string passed) {
	ofstream os("data.txt",ofstream::app);	
	os << "id:\t" << id << endl << "passed:\t" << passed << endl << endl;
	os.close();
}

int main() {
	insert_item("123", "456"); 
	return 0;
} 

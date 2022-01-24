#include<iostream>
#include<set>
using namespace std; 
int main() {
	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	cout << ms.count(1) << endl;
	return 0;
}

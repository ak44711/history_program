#include<iostream>
using namespace std;
int lowbit(int x)  {
	return x & (-x);
}
int main() {
	cout << lowbit(10) << endl;
	return 0;
} 

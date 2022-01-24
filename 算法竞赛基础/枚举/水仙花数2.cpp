#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int t;
	for(int i = 1; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 10; k++) {
				t = i * 100 + j * 10 + k;
				if(pow(i,3) + pow(j,3) + pow(k,3) == t){
					cout << t << endl;
				}
			}
		}
	}
	return 0;
}

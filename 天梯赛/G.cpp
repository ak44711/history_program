#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	int Max = -1, maxCnt = 0;
	int Min = 1e7, minCnt = 0;
	int t;
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		if(t > Max){
			Max = t;
			maxCnt = 1;
		}else if(t == Max) {
			maxCnt++;
		}
		if(t == Min) {
			minCnt++;
		}else if(t < Min) {
			Min = t;
			minCnt = 1;
		}
 	}
 	cout << Min << " " << minCnt << endl;
 	cout << Max << " " << maxCnt << endl;
	return 0;
}

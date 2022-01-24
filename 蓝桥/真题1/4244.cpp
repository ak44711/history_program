#include<iostream>

#include<map>
#include<set>
#include<vector>
#include<list>
#include<queue>
#include<stack>



using namespace std;
int main() {
	
	
	
	
	int n, m;
	cin >> n >> m;
	int ls[n];
	for(int i = 0; i < n; i++) {
		ls[i] = i + 1;		
	}
	int index = 0;
	while(n) {
		index  = (index + m - 1) % n;
		cout  << ls[index] << " ";
		for(int i = index + 1; i < n; i++) {
			ls[i - 1] = ls[i];
		}
		n--;
	}
	cout << endl;
	return 0;
} 

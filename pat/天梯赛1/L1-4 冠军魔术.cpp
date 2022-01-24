#include<iostream>
using namespace std;
int main() {
	int card, cnt;
	cin >> card >> cnt;
	int coin = 0;
	for(int i = 0; i < cnt; i++) {
		swap(coin, card);
		if(i % 2 == 1) {
			card *= 2;
		}
	}
	if(card) {
		cout << "0 " << card << endl;
	}else{
		cout << "1 " << coin << endl;
	}
	return 0;
}

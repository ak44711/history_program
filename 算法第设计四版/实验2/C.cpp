#include<iostream>
#include<vector>
using namespace std;

int compare_times = 0;
bool knowFlag = false; 
bool isHeavy; 

int total_weigh(vector<int>& coins, int le, int ri) {//[le, ri)
	int weight = 0;
	for(int i = le; i < ri - le; i++) {
		weight += coins[i];
	}
	return weight;
}
int compare(int a, int b) {
	if(a > b) return 1;
	if(a < b) return -1;
	return 0;
}
int find_fake_coin(vector<int>& coins, int le, int ri){//[le, ri)
	int cnt = ri - le;
	int a = (cnt - cnt % 3) / 3;
	int weigha = total_weigh(coins, le, a);
	int b = (cnt - cnt % 3) / 3;
	int weighb = total_weigh(coins, a, 2 * a);
	int c = (cnt - cnt % 3) / 3;
	int weighc = total_weigh(coins, 2 * a, 3 * a);
	int d = cnt % 3;
	int weighd = total_weigh(coins, 3 * a, ri);
	if(compare(a,b) == 0) {//a,b堆质量相同 
		compare_times++;
		if(compare(a, b) ) 
	}
	
}
int main() {
	vector<int> coins = {	1,1,1,1,1,
							1,1,1,1,1,
							1,1,2,1,1};
	
	return 0;
} 

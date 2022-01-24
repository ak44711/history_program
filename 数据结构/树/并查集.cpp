#include<iostream>
using namespace std;
const int N = 1e3 + 10;
struct node{
	int depth;
	int father;
}mfset[N];

int init_set() {
	for(int i = 0; i < N; i++) {
		mfset[i].depth = 1;
		mfset[i].father = i;
	}//for
}
//²é
int find_set(int x) {
	while(mfset[x].father != x) x = mfset[x].father;
	return x;
}
//²¢ 
void merge_set(int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if(x == y) return;
	else if(mfset[x].depth < mfset[y].depth) {
		mfset[x].father = y;
	}else if(mfset[x].depth > mfset[y].depth){
		mfset[y].father = x;
	}else{
		mfset[y].father = x;
		mfset[y].depth++;
	}
}

void test(int es[]) {
	init_set();
}
int main() {
		
	return 0;
}

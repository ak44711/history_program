#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int N;
int main() {
	scanf("%d", &N);
	int t;
	multiset<int> s;
	for(int i = 0; i < N; i++) {
		scanf("%d", &t);
		s.insert(t);
	}
	int cost = 0;
	while(s.size() > 1) {
		int min1 = *(s.begin());
		s.erase(s.begin());
		int min2 = *(s.begin());
		s.erase(s.begin());
		int sum = min1 + min2;
		s.insert(sum);
		cost += sum;
	}
	if(N == 1) cost = *(s.begin());
	printf("%d\n", cost);
	return 0;
}
/*
3 
8 5 8
*/

#include<iostream>
#include<algorithm>
using namespace std; 
const int N = 1e4;
struct activity{
	int start;
	int end;
}a[N];

bool cmp(activity& a1, activity& a2) {
	return a1.end < a2.end;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].start);
		scanf("%d", &a[i].end);
	}
	/*按照时间结束的时间去排序，
	记录最后一个选择的活动a[j],
	如果新的活动a[i]的开始时间晚于a[j],说明时间不冲突 
		将最后一个活动更新:j=i 
	*/
	sort(a, a + n, cmp);
	int t = 1;
	int j = 0;
	for(int i = 1; i < n; i++) {
		if(a[i].start >= a[j].end) {
			t++;
			j = i;
		}
	}
	printf("%d\n", t);
	return 0;
} 
/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/

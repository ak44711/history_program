#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

typedef long long LL;
const int N = 2 * 1e6 + 100;
LL f[N] = {0};//前缀和数组 
LL que[N] = {0};//优先队列 
LL s[N] = {0};//从i开始、长度为d的区间和 
int pos[N] = {0};

int main() {
	int n, d; 
	LL x, p;
	scanf("%d%lld%d", &n, &p, &d);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &x);//输入数字 
		f[i] = f[i - 1] + x;//维护前缀和数组 
	}
	for(int i = 1; i <= n - d + 1; i++) {
		s[i] = f[i + d - 1] - f[i - 1];//s[i]为区间[i, i + d - 1]的和
	}
	int head = 1, tail = 0, l = 0;
	int ans = d;
	//用 l 和 i维护选择的区间
	//head 、 tail 维护队列区间 
	for(int i = d, j = 1; i <= n; i++, j++) {
		while(head <= tail && que[tail] <= s[j]) tail--;//将优先队列中队尾小于s[j]的元素出队 
		que[++tail] = s[j];//s[j]入队 
		pos[tail] = j;//记录s[j] 的位置 
		while(l < i && head <=tail && f[i] - f[l] - que[head] > p) {//当区间内不满足条件时，即区间内元素总和 - 最大可置零区间 > 可允许的元素总和大小 
			l++;// 
			if(l >= pos[head] ) head++;
		}
		ans = max(ans, i - l);//
	}
	printf("%d", ans);
	return 0;
}

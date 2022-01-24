#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

typedef long long LL;
const int N = 2 * 1e6 + 100;
LL f[N] = {0};//ǰ׺������ 
LL que[N] = {0};//���ȶ��� 
LL s[N] = {0};//��i��ʼ������Ϊd������� 
int pos[N] = {0};

int main() {
	int n, d; 
	LL x, p;
	scanf("%d%lld%d", &n, &p, &d);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &x);//�������� 
		f[i] = f[i - 1] + x;//ά��ǰ׺������ 
	}
	for(int i = 1; i <= n - d + 1; i++) {
		s[i] = f[i + d - 1] - f[i - 1];//s[i]Ϊ����[i, i + d - 1]�ĺ�
	}
	int head = 1, tail = 0, l = 0;
	int ans = d;
	//�� l �� iά��ѡ�������
	//head �� tail ά���������� 
	for(int i = d, j = 1; i <= n; i++, j++) {
		while(head <= tail && que[tail] <= s[j]) tail--;//�����ȶ����ж�βС��s[j]��Ԫ�س��� 
		que[++tail] = s[j];//s[j]��� 
		pos[tail] = j;//��¼s[j] ��λ�� 
		while(l < i && head <=tail && f[i] - f[l] - que[head] > p) {//�������ڲ���������ʱ����������Ԫ���ܺ� - ������������ > �������Ԫ���ܺʹ�С 
			l++;// 
			if(l >= pos[head] ) head++;
		}
		ans = max(ans, i - l);//
	}
	printf("%d", ans);
	return 0;
}

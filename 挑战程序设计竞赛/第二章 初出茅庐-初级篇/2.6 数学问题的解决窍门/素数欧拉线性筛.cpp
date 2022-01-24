#include<cstdio>
#include<cstring>
/*
ÿ��������������С����Pmin��t��ʾ 
�¼����Ӷ� nlogn 
*/
typedef long long ll;
const ll maxn = 1e6 + 10;

bool isPrime[maxn];
int prime[maxn];
int cnt = 0;

int main() {
	int step = 0;
	memset(isPrime, 0, sizeof(isPrime));
	int n = 500;
	isPrime[0] = 1;
	isPrime[1] = 1;
	for(int i = 2; i <= n; i++) {
		/**/printf("%d -- ", i);
		if(isPrime[i] == 0) {//���һ����û�б����Ϊ�����������ж�Ϊ������������������ 
			prime[cnt++] = i;
		}
		/**/printf("\t%d ", isPrime[i]);
		for(int j = 0; j < cnt && prime[j] * i <= n; j++) {//���䱶�����λ������
			step++;
			isPrime[i * prime[j]] = 1;//���Ϊ������
			/**/printf("%d ", i * prime[j]);
			if(i % prime[j] == 0) break;//���i��prime[j]����С���ӣ���ֹͣ���
		}
		/**/printf("\n");
	}
	printf("%d", step);
	return 0;
} 

 #include<iostream>
 using namespace std;
 int t1[1001];//ǰ�� 
 int t2[1001];//����
void sousuo(int a, int b, int n, int flag) {
	if(n == 1) {
		printf("%d ", t1[a]);
		return;
	}else if(n <= 0){
		return;
	}
	int i;
	for(i = 0; t1[a] != t2[b + i]; i++) ;//��������ĵ�һ�����Ǹ��ڵ㣬������������������ҵ����ڵ� 
	sousuo(a + 1, b, i, 0);//
	sousuo(a + i + 1, b + i + 1, n - i - 1, 0);
	if(flag == 1)
		printf("%d", t1[a]);
	else
		printf("%d ", t1[a]);
}
 int main() {
 	int n, i;
 	while(scanf("%d", &n) != EOF){
 		for(int i = 1; i <= n; i++) {
 			scanf("%d", &t1[i]);
		}
		for(int i = 1; i <= n; i++) {
 			scanf("%d", &t2[i]);
		}
		sousuo(1,1,n,1);
		printf("\n");
	 }
 	return 0;
 }
 /*
 9
 1 2 4 7 3 5 8 9 6
 4 7 2 1 8 5 9 3 6
 */

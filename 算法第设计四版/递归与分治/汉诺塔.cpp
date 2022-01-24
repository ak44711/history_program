#include<iostream> 
using namespace std;
int cnt;
void hanoi(int n, char a, char b, char c) {
	if (n == 0)
		return;
	hanoi(n - 1, a, c, b);//��n-1��������A����C�ƶ���B
	printf ("step %d: move %d from %c->%c\n", cnt++, n, a, c);
	hanoi(n - 1, b, a, c);//ʣ�µ�n-1���ӣ���B����A�ƶ���C
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 'a', 'b', 'c');
	return 0;
}

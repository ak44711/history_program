/*堆的定义：
  1完全二叉树，
  2父节点的值大于子节点的值 
*/
#include<cstdio>
using namespace std;
int main() {
	int n = 4;
	for(int i = 1; i < 16; i++) {
		printf("%d\n", n);
		n*=4;
	}
} 

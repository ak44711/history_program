#include<iostream>
#include<queue>
using namespace std;
inline int huffman(priority_queue<int, vector<int>, greater<int>>& heap) {
    int cost = 0;
    /*每次找到两个最小的节点，获得一个新的节点，插入到最小堆中
	  最小的两个节点相加，相当于把两个节点包含的叶子节点权重再加一次
	  到最后所有叶子节点的权重都会被加该叶子节点的层数次。 
	*/
    while(heap.size() > 1) {
        int c = heap.top();
        heap.pop();
        c += heap.top();
        heap.pop();
        cost += c;
        heap.push(c);
    }
    return cost;
}
int main() {
	int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0, x; i < n; i++) {
    	scanf("%d", &x);
    	heap.push(x);
	}
    printf("%d\n", huffman(heap));
    return 0;
}

#include<iostream>
#include<queue>
using namespace std;
inline int huffman(priority_queue<int, vector<int>, greater<int>>& heap) {
    int cost = 0;
    /*ÿ���ҵ�������С�Ľڵ㣬���һ���µĽڵ㣬���뵽��С����
	  ��С�������ڵ���ӣ��൱�ڰ������ڵ������Ҷ�ӽڵ�Ȩ���ټ�һ��
	  ���������Ҷ�ӽڵ��Ȩ�ض��ᱻ�Ӹ�Ҷ�ӽڵ�Ĳ����Ρ� 
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

#include<iostream>
#include<queue>
using namespace std;

struct node{
	int w;
	char c;
	node* left;
	node* right;
};
/*
    哈夫曼树的定义 
	节点的带权路径长度长度为从该节点到树根的路径长度和节点上权的乘积 
	树的带权路径长度是书中所有椅子节点的带权路径之和记作WPL
	哈夫曼树，又称最优树，是一类带权路径长度最短的树。
	
	哈夫曼树的构造方法 
	(1)根据给定的n个权重{w1, w2,..., wn}构成n颗二叉树的集合F={T1, T2,... Tn}
	其中每棵树Ti只有一个带权为wi的根节点，其左右子树都为空。
	(2)在F中选取两棵根节点的权值最小的树作为左右子树构造一棵新的二叉树，
  且新置的二叉树的根节点的权值为其左右子树上根节点的权值之和。 
  	(3)在F中删除这两棵二叉树，并将新置的二叉树加入F中
	(4)重复(2)、(3)操作，直到F只含一棵树为止 
	
	  
	*/
inline int huffman(priority_queue<int, vector<int>, greater<int>>& heap) {
	priority_queue<int, vector<int>, greater<int>> heap;
    int cost = 0;
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
    
    for(int i = 0, x; i < n; i++) {
    	scanf("%d", &x);
    	heap.push(x);
	}
    printf("%d\n", huffman(heap));
    return 0;
}

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
    ���������Ķ��� 
	�ڵ�Ĵ�Ȩ·�����ȳ���Ϊ�Ӹýڵ㵽������·�����Ⱥͽڵ���Ȩ�ĳ˻� 
	���Ĵ�Ȩ·�������������������ӽڵ�Ĵ�Ȩ·��֮�ͼ���WPL
	�����������ֳ�����������һ���Ȩ·��������̵�����
	
	���������Ĺ��췽�� 
	(1)���ݸ�����n��Ȩ��{w1, w2,..., wn}����n�Ŷ������ļ���F={T1, T2,... Tn}
	����ÿ����Tiֻ��һ����ȨΪwi�ĸ��ڵ㣬������������Ϊ�ա�
	(2)��F��ѡȡ���ø��ڵ��Ȩֵ��С������Ϊ������������һ���µĶ�������
  �����õĶ������ĸ��ڵ��ȨֵΪ�����������ϸ��ڵ��Ȩֵ֮�͡� 
  	(3)��F��ɾ�������ö��������������õĶ���������F��
	(4)�ظ�(2)��(3)������ֱ��Fֻ��һ����Ϊֹ 
	
	  
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

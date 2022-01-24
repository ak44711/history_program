#include<iostream>
using namespace std;
const int N = 2e5;
int h[N], len;
int n;

void down(int u) {
    int t = u;
    if(u * 2 <= len && h[u * 2] < h[t]) t = 2 * u;
    if(u * 2 + 1 <= len && h[u * 2 + 1] < h[t]) t = 2 * u + 1;
    if(u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u) {
	while(u / 2 && h[u / 2] > h[u]){
		swap(h[u / 2], h[u]);
		u /= 2;
	}
}
//数组建堆，O(n) 
void create_heap(){
	for(int i = n / 2; i; i--) {
        down(i);
    }
}

void insert_heap(int x) {
	h[++len] = x;
	up(len);
}

int get_top() {
	return h[1];
}

void erase_top() {
	h[1] = h[len];
	len--;
	down(1);
}

void print_heap(int n) { 
	for(int i = 1; i <= n; i++) {
		printf("%d ", h[i]); 
	}
	printf("\n");
}

/*
*堆排序（小顶堆可以拍成 从大到小的非递减序列） 
*[最小][无序][有序]-----------第i轮 
*[1][2: k][k + 1: n]----------
*[最小][无序][有序]-----------第i+1轮 
*[1][2: k - 1][k: n]----------

*1号元素换到无序部分的最后一个位置，使其和有序部分有序
*然后使用down(1)操作使其变成规模更小，结构相同的子问题
*因为是尾递归所以可以迭代
*/
int heap_sort() {
	//1.建堆
	create_heap();
	int n = len;
	cout << "建堆: ";print_heap(n);
	cout << endl;
	for(int i = len; i >= 1; i--) {
		//对顶放到为就绪 
		swap(h[i], h[1]);
		cout << "i:" << i << endl ; 
		cout << "swap: "; print_heap(n);
		len--;
		down(1);
		cout << "down: ";
		print_heap(n);
		cout << endl;
	}
}

int bin_search(int nums[], int len, int target) {
	cout << endl << "target: " << target << " " << len << endl;
	int left = 1;
    int right = len;	// 定义了target在左闭右闭的区间内，[left, right]
    while (left <= right) {	//当left == right时，区间[left, right]仍然有效
        int middle = left + ((right - left) / 2);//等同于 (left + right) / 2，防止溢出
        cout << nums[left] << " " << nums[middle] << " " << nums[right] << endl;
        if (nums[middle] < target) {
            right = middle - 1;	//target在左区间，所以[left, middle - 1]
        } else if (nums[middle] > target) {
            left = middle + 1;	//target在右区间，所以[middle + 1, right]
        } else {//命中 
            return middle;
        }
    }
    //没有找到目标值
    return -1;
} 

int main() {
    scanf("%d", &n);
    len = n;
    //下标从1开始 
    for(int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    heap_sort();
    for(int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
	cout<< endl << "bin_search:" << bin_search(h, n, 1) << endl;
    return 0;
}

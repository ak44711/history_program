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
//���齨�ѣ�O(n) 
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
*������С���ѿ����ĳ� �Ӵ�С�ķǵݼ����У� 
*[��С][����][����]-----------��i�� 
*[1][2: k][k + 1: n]----------
*[��С][����][����]-----------��i+1�� 
*[1][2: k - 1][k: n]----------

*1��Ԫ�ػ������򲿷ֵ����һ��λ�ã�ʹ������򲿷�����
*Ȼ��ʹ��down(1)����ʹ���ɹ�ģ��С���ṹ��ͬ��������
*��Ϊ��β�ݹ����Կ��Ե���
*/
int heap_sort() {
	//1.����
	create_heap();
	int n = len;
	cout << "����: ";print_heap(n);
	cout << endl;
	for(int i = len; i >= 1; i--) {
		//�Զ��ŵ�Ϊ���� 
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
    int right = len;	// ������target������ұյ������ڣ�[left, right]
    while (left <= right) {	//��left == rightʱ������[left, right]��Ȼ��Ч
        int middle = left + ((right - left) / 2);//��ͬ�� (left + right) / 2����ֹ���
        cout << nums[left] << " " << nums[middle] << " " << nums[right] << endl;
        if (nums[middle] < target) {
            right = middle - 1;	//target�������䣬����[left, middle - 1]
        } else if (nums[middle] > target) {
            left = middle + 1;	//target�������䣬����[middle + 1, right]
        } else {//���� 
            return middle;
        }
    }
    //û���ҵ�Ŀ��ֵ
    return -1;
} 

int main() {
    scanf("%d", &n);
    len = n;
    //�±��1��ʼ 
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

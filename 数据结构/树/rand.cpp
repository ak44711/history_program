#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int N = 1e5 + 10;

/**
 *input	a	����������
 *input	l	�������������߽�
 *input	r	������������ұ߽�
 *input	k	��kС
 *return	��kС��Ԫ��
 */
int quickselect(int a[], int l, int r, int k) {
    if(l >= r) return a[l];
    int i = l - 1, j = r + 1;
    srand((unsigned) time (NULL));
    int x= a[l + rand() % (r - l + 1)];//x��l��r�е����������
    
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    if(j - l + 1 >= k) return quickselect(a, l, j, k);
    else return quickselect(a, j + 1, r, k - (a, j - l  + 1));
}

int main() {
    int a[N], n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    cout << quickselect(a, 0, n - 1, k) << endl;
    return 0;
}

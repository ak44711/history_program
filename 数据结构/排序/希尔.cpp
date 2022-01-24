#include <iostream>
using namespace std;
void shsort(int s[], int n)    /* 自定义函数 shsort()*/
{
    int i,j,d;
    d=n/2;    /*确定固定增虽值*/
    while(d>=1)
    {
        for(i=d+1;i<=n;i++)    /*数组下标从d+1开始进行直接插入排序*/
        {
            s[0]=s[i];    /*设置监视哨*/
            j=i-d;    /*确定要进行比较的元素的最右边位置*/
            while((j>0)&&(s[0]<s[j]))
            {
                s[j+d]=s[j];    /*数据右移*/
                j=j-d;    /*向左移d个位置V*/
            }
            s[j + d]=s[0];    /*在确定的位罝插入s[i]*/
        }
        d = d/2;    /*增里变为原来的一半*/
    }
}
void shellSort(int array[], int len)
{
	int i, j, gap;
	//gap是增量
	for (gap = len / 2; gap > 0; gap = gap / 2)
		//以gap为间距的子序列进行插入排序 
		for (i = gap; i < len; i++)
			for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j = j - gap)
				swap(array[j], array[j + gap]);
}
int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int n = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	shellSort(arr, 10);
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
} 

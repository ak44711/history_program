#include <iostream>
using namespace std;
void shsort(int s[], int n)    /* �Զ��庯�� shsort()*/
{
    int i,j,d;
    d=n/2;    /*ȷ���̶�����ֵ*/
    while(d>=1)
    {
        for(i=d+1;i<=n;i++)    /*�����±��d+1��ʼ����ֱ�Ӳ�������*/
        {
            s[0]=s[i];    /*���ü�����*/
            j=i-d;    /*ȷ��Ҫ���бȽϵ�Ԫ�ص����ұ�λ��*/
            while((j>0)&&(s[0]<s[j]))
            {
                s[j+d]=s[j];    /*��������*/
                j=j-d;    /*������d��λ��V*/
            }
            s[j + d]=s[0];    /*��ȷ����λ�D����s[i]*/
        }
        d = d/2;    /*�����Ϊԭ����һ��*/
    }
}
void shellSort(int array[], int len)
{
	int i, j, gap;
	//gap������
	for (gap = len / 2; gap > 0; gap = gap / 2)
		//��gapΪ���������н��в������� 
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

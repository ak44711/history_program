#include<iostream>
#include<vector> 
using namespace std;
/*计算分组钱币总质量*/
int count(vector<int>& a,int begin,int end){
    int sum = 0;
    for (int i = begin; i <=end;i++){
        sum += a[i];
    }
    return sum;
}

void find(vector<int>& a,int begin,int end){
    int mid = (begin + end) / 2;
    if(end-begin==1&&a[begin]>a[end]) { //递归出口，end-begin代表只剩两个数（针对个数为偶数）
        cout << "find fake money: " << end+1 << endl;
        return ;
    }
    if(end-begin==1&&a[begin]<a[end]) {//递归出口，end-begin代表只剩两个数（针对个数为偶数）
        cout << "find fake money: " << begin+1 << endl;
        return ;
    }
    if(begin-end==0) {//递归出口，end-begin代表只剩一个数(针对个数为奇数)
        cout << "find fake money" <<a[mid]<< endl;
        return ;
    }
    if((begin+end)%2==1) {//传入个数为奇数
        if(count(a,begin,mid)<count(a,mid+1,end)){ //(前面半组比后面半组轻)
             find(a, begin,  mid );
        }
        if(count(a,mid+1,end)<count(a,begin,mid)) {//前边半组比后面半组重
             find(a, mid+1,  end);
        }
    }
    if((begin+end)%2==0&&count(a,begin,mid-1)==count(a,mid+1,end)) {//针对数组元素为个数时，两边数组相同则中间即为我们要找的假币
        cout<<"Counterfeit money in the first"<<mid<<"individual"<<"The quality of"<<a[mid]<<endl;
        return;
    }
    if((begin+end)%2==0) {//针对数组个数为偶数
        if(count(a,begin,mid-1)<count(a,mid+1,end)) {//前面比后面轻，递归前面
             find(a, begin, mid - 1);
        }
        if(count(a,begin,mid-1)>count(a,mid+1,end)) {//前面比后面中，递归后面
             find(a, mid + 1, end);
        }
    }
}
//测试
int main() {
    vector<int> a = {2,2,2,2,2,2,2,2,1};
    find(a, 0,a.size() - 1);
    vector<int> a1 = {2,2,2,2,1,2,2,2,2,2};
    find(a1, 0,a1.size() - 1);
    vector<int> a2 = {3,2,2,2,2,2,2,2,2,2};
    find(a2, 0,a2.size() - 1);
    return 0;
}


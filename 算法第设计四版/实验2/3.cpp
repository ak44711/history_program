#include<iostream>
#include<vector> 
using namespace std;
/*�������Ǯ��������*/
int count(vector<int>& a,int begin,int end){
    int sum = 0;
    for (int i = begin; i <=end;i++){
        sum += a[i];
    }
    return sum;
}

void find(vector<int>& a,int begin,int end){
    int mid = (begin + end) / 2;
    if(end-begin==1&&a[begin]>a[end]) { //�ݹ���ڣ�end-begin����ֻʣ����������Ը���Ϊż����
        cout << "find fake money: " << end+1 << endl;
        return ;
    }
    if(end-begin==1&&a[begin]<a[end]) {//�ݹ���ڣ�end-begin����ֻʣ����������Ը���Ϊż����
        cout << "find fake money: " << begin+1 << endl;
        return ;
    }
    if(begin-end==0) {//�ݹ���ڣ�end-begin����ֻʣһ����(��Ը���Ϊ����)
        cout << "find fake money" <<a[mid]<< endl;
        return ;
    }
    if((begin+end)%2==1) {//�������Ϊ����
        if(count(a,begin,mid)<count(a,mid+1,end)){ //(ǰ�����Ⱥ��������)
             find(a, begin,  mid );
        }
        if(count(a,mid+1,end)<count(a,begin,mid)) {//ǰ�߰���Ⱥ��������
             find(a, mid+1,  end);
        }
    }
    if((begin+end)%2==0&&count(a,begin,mid-1)==count(a,mid+1,end)) {//�������Ԫ��Ϊ����ʱ������������ͬ���м伴Ϊ����Ҫ�ҵļٱ�
        cout<<"Counterfeit money in the first"<<mid<<"individual"<<"The quality of"<<a[mid]<<endl;
        return;
    }
    if((begin+end)%2==0) {//����������Ϊż��
        if(count(a,begin,mid-1)<count(a,mid+1,end)) {//ǰ��Ⱥ����ᣬ�ݹ�ǰ��
             find(a, begin, mid - 1);
        }
        if(count(a,begin,mid-1)>count(a,mid+1,end)) {//ǰ��Ⱥ����У��ݹ����
             find(a, mid + 1, end);
        }
    }
}
//����
int main() {
    vector<int> a = {2,2,2,2,2,2,2,2,1};
    find(a, 0,a.size() - 1);
    vector<int> a1 = {2,2,2,2,1,2,2,2,2,2};
    find(a1, 0,a1.size() - 1);
    vector<int> a2 = {3,2,2,2,2,2,2,2,2,2};
    find(a2, 0,a2.size() - 1);
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;
//����ȫ���У� ����ÿһ����� 
void dfs(vector<int>& v, int first, int len) {
	if(len == first) {
		for(int i = 0; i < len; i++) {
			cout << v[i] << " ";
		}
		//ֻ��ѡ��ǰ��������ѡ����λ������λ�����㷽��Ϊ�������ܺͼ�ȥ������С���� 
		cout<< "�������е�һ���������С����Ϊ��" << v[0] + v[1] + v[2] - max(max(v[0], v[1]), v[2]) - min(min(v[0], v[1]), v[2])<< endl;
		return;
	}
	for(int i = first; i < len; i++) {
		swap(v[first], v[i]);
		dfs(v, first + 1, len);
		swap(v[first], v[i]);
	}
}

int main(){
	int n = 4;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		v[i] = i + 1;
	}
	dfs(v, 0, n);
	return 0;
} 

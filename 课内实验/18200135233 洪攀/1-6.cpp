#include <iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int f(vector<int>& P, int x, int& cnt) {
	int y = P[0];
	int power = 1;
	for(int i = 1; i <= P.size(); i++) {
		power *= x;
		y += P[i] * power;
		cnt++; 
	}
	return y;
}

int main(){
	int n, x;
	cout << "��Ҫ������ĸ�����" << endl; 
	cin >> n;
	
    srand((int)time(0));
    int t;
    vector<int> arr(n + 1);
    for (int i = 0; i <= n; i++){
    	t = rand()%10 + 1;
    	arr[i] = t;
        printf("%-4d", t);
    }
    cout << endl;
    
    cout << "������ʵ��x��" << endl; 
	cin >> x; 
	
	int cnt;
	cout << "�������" << f(arr, x, cnt) << endl;
	cout << "�ӷ��ͳ˷�ִ�д���" << cnt << endl;
    return 0;
}

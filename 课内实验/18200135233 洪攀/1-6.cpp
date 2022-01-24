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
	cout << "需要随机数的个数：" << endl; 
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
    
    cout << "请输入实数x：" << endl; 
	cin >> x; 
	
	int cnt;
	cout << "函数结果" << f(arr, x, cnt) << endl;
	cout << "加法和乘法执行次数" << cnt << endl;
    return 0;
}

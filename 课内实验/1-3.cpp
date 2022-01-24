#include <iostream>
#include<vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int n;
	cout << "需要随机数的个数：" << endl; 
	cin >> n;
    srand((int)time(0));
    int t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
    	t = rand()%100 + 1;
    	arr[i] = t;
        printf("%-4d", t);
    }
    cout << endl;
    
    for(int i = 0; i < n; i++) {
    	if(arr[i] % 2 == 0) {
    		printf("%-4d", arr[i]);
		}else {
			printf("%-4d", arr[i] * 2);
		}
	}
	cout << endl;
    return 0;
}

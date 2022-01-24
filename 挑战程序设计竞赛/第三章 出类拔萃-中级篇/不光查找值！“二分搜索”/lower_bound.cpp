#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<map> 
using namespace std;
const int maxn = 1e6+10;
int arr[maxn];

lower_find(int x, int* arr, int len) {
	
}

int main() {
	int n = 20;
	srand((int)time(0));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	unordered_map<int, int> m;
	return 0;
} 

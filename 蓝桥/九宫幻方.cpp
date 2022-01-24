/*有意思的是，所有的三阶幻方，
都可以通过这样一个九宫格进行若干镜像和旋转操作之后得到。 
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<string> vs(8);
		vs[0] = "492357816",
		vs[1] = "276951438",
		vs[2] = "618753294",
		vs[3] = "834159672",
		vs[4] = "294753618",
		vs[5] = "672159834",
		vs[6] = "816357492",
		vs[7] = "438951276";
	vector<int> input(9);
	for(int i = 0; i < 9; i++){
		cin >> input[i];
	}
	int cnt = 0;
	int index = -1;
	int i = 0, j = 0;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 9; j++){
			if(vs[i][j] != input[j] + '0' && input[j] != 0){
				break;
			}
		}
		if(j == 9){//找到一组 
			index = i;
			cnt++;
			if(cnt >= 2){//已找到多组 
				break;
			}
		}
	}
	if(cnt == 1){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cout << vs[index][i * 3 + j] << " ";
			}
			cout << endl;
		}
	}else if(cnt > 1){
		cout << "Too Many" << endl;
	}
	return 0;
} 

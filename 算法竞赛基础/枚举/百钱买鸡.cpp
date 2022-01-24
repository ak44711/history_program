#include<iostream>
using namespace std;
int main(){
	int x, y, z; 
	for(x = 0; x < 100; x++){
		for(y = 0; y < 100 - x; y++){
			z = 100 - x - y;
			if(z % 3 == 0 && 3 * x + 5 * y + z / 3 == 100){
				cout << x << " " << y << " " << z << endl;
			}
		}
	}
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double R,X,Y;
	cin >> R >> X >> Y;
	double d = sqrt(X * X + Y * Y);
	if(d < R) {
		cout << 2 << endl;
	}else {
		int ans = int(d) / R;
		if(ans * R != d) ans++;
		cout << ans << endl;
	}
	return 0;
}

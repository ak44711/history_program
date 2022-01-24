#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string add(string x, string y) {//大整数加法
	string z;
	int nx = x.size();
	int ny = y.size();
	int flag = 0;
	for (int i = 0; i < max(nx, ny); i++) {
		int t = 0;
		if (nx - 1 - i >= 0) {
			t += x[nx - 1 - i] - '0';
		}
		if (ny - 1 - i >= 0) {
			t += y[ny - 1 - i] - '0';
		}
		if (flag) {
			t++;
			flag = 0;
		}
		if (t >= 10) {
			flag = 1;
			t -= 10;
		}
		string now = " ";
		now[0] = t + '0';
		z = now + z;
	}
	if (flag == 1) {
		z = "1" + z;
	}
	return z;
}
string mul(string x, string y) {//大整数乘法
	if (x.size() == 1 && y.size() == 1) {//若俩个乘数都只有一位，则为最终状态，直接相乘赋值给now，返回该string
		int a = x[0] - '0';
		int b = y[0] - '0';
		string now;
		if (a * b >= 10) {
			now += (a * b / 10) + '0';
			now += (a * b % 10) + '0';
		}
		else {
			string now1 = " ";
			now1[0] = (a * b) + '0';
			now += now1[0];
		}
		return now;
	}
	else if (x.size() == 1) {//乘数x只有一位，特殊考虑
		if (x == "0") {
			return "0";
		}
		int ny = y.size() / 2;
		string yh = y.substr(0, ny);
		string yl = y.substr(ny, y.size() - ny);
		string xyh = mul(x, yh);
		for (int i = 0; i < y.size() - ny; i++) {
			xyh = xyh + "0";
		}
		string xyl = mul(x, yl);
		return add(xyh, xyl);
	}
	else if (y.size() == 1) {//乘数y只有一位，特殊考虑
		if (y == "0") {
			return "0";
		}
		int nx = x.size() / 2;
		string xh = x.substr(0, nx);
		string xl = x.substr(nx, x.size() - nx);
		string xhy = mul(xh, y);
		for (int i = 0; i < x.size() - nx; i++) {
			xhy = xhy + "0";
		}
		string xly = mul(xl, y);
		return add(xhy, xly);
	}
	else {//将乘数分为xh，xl，yh，yl，递归
		int nx = x.size() / 2;
		int ny = y.size() / 2;
		string xh = x.substr(0, nx);
		string yh = y.substr(0, ny);
		string xl = x.substr(nx, x.size() - nx);
		string yl = y.substr(ny, y.size() - ny);

		string xhyh = mul(xh, yh);
		for (int i = 0; i < x.size() - nx + y.size() - ny; i++) {
			xhyh = xhyh + "0";
		}
		string xhyl = mul(xh, yl);
		for (int i = 0; i < x.size() - nx; i++) {
			xhyl = xhyl + "0";
		}
		string xlyh = mul(xl, yh);
		for (int i = 0; i < y.size() - ny; i++) {
			xlyh = xlyh + "0";
		}
		string xlyl = mul(xl, yl);
		return add(add(xhyh, xhyl), add(xlyh, xlyl));
	}
}
int main()
{
	string x, y;
	cin >> x >> y;
	cout << mul(x, y) << endl;
	return 0;
}

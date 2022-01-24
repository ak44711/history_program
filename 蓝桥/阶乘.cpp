#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
/*
	55
*	49
-------
	941
*/

string add(string& v1, string& v2){
	int size1 = v1.size();
	int size2 = v2.size();
	string res;
	int minsize = (size1 < size2 ? size1 : size2);
	int i = 0;
	int carry = 0;
	
	while(i < minsize){
		carry += v1[i] + v2[i] - '0' - '0';
		res.push_back(carry % 10 + '0');
		carry /= 10;
		i++;
	}
	while(i < size1) {
		carry += v1[i] - '0';
		res.push_back(carry % 10 + '0');
		carry /= 10;
		i++;
	}
	while(i < size2) {
		carry += v2[i] - '0';
		res.push_back(carry % 10 + '0');
		carry /= 10;
		i++;
	}
	if(carry == 1){
		res.push_back('1');
	}
	//cout << res;
	return res;
}

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	s3 = add(s1, s2);
	reverse(s3.begin(), s3.end());
	cout << s3 << endl;
	return 0;
} 

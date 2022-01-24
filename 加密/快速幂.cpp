#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/*******************************************************************************************************/
vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size(), 0); // 初始化为 0，且999*99最多 5 位
    long long int u = 0;
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B.size(); j++){
        	C[i + j] += A[i] * B[j];
		}
    }
    int t = 0;
    for (int i = 0; i < C.size(); i++) { // i = C.size() - 1时 t 一定小于 10
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 必须要去前导 0，因为最高位很可能是 0
    return C;
}

/*******************************************************************************************************/

/*******************************************************************************************************/

const long long G = 3, Ginv =332748118, P = 998244353;
vector<long long> flip_bin;
long long fastpow(long long a, long long n);
string multiply(string num1, string num2);
void ntt(vector<long long>& a, bool inv=false);
/*******************************************************************************************************/

/*******************************************************************************************************/


int main1() {
//	ios::sync_with_stdio(false);
    string a;
    long long int b;
    cin >> a;
	cin >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    vector<int> temp = A;
    vector<int> ans = {1};
	while(b > 0) {
    	if(b & 0x1 == 1) ans = mul(temp, ans);
		temp = mul(temp, temp);
		b /= 2;
	}
	cout << ans.size() << endl; 
    return 0;
}

int main() {
	ios::sync_with_stdio(false);
	string a;
	int b;
	cin >> a >> b;
	string ans("1");
	string temp = a;
	while(b > 0) {
    	if(b & 0x1 == 1) ans = multiply(temp, ans);
		temp = multiply(temp, temp);
		b /= 2;
	}
	cout << ans << endl; 
	ofstream os("1a.txt");
	os << ans.size() << endl;
	os << ans << endl;
}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int len1 = num1.size(), len2 = num2.size(), n = 1, N = 1;
    while ((n <<= 1) < (len1 + len2)) ++N;
    flip_bin.resize(n);
    for (int i = 0; i < n; ++i) 
        flip_bin[i] = (flip_bin[i >> 1] >> 1) | ((i & 1) << (N - 1));

    vector<long long> a(n, 0), b(n, 0);
    for (int i = 0; i < len1; ++i) a[i] = num1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; ++i) b[i] = num2[len2 - 1 - i] - '0';
    ntt(a);
    ntt(b);
    for (int i = 0; i < n; ++i) a[i] = (a[i] * b[i]) % P;
    ntt(a, true);

    long long inv = fastpow(n, P - 2);
    string res;
    long long prev = 0;
    for (int i = 0; i < len1 + len2 - 1; ++i) {
        long long curr = a[i] * inv % P + prev;
        res = static_cast<char>(curr % 10 + '0') + res;
        prev = curr / 10;
    }
    while (prev) {
        res = static_cast<char>(prev % 10 + '0') + res;
        prev /= 10;
    }
    return res;
}

long long fastpow(long long a, long long n) {
    long long res = 1;
    do {
        if (n & 1) res = (res * a) % P;
        a = (a * a) % P;
    } while (n >>= 1);
    return res % P;
}

void ntt(vector<long long>& a, bool inv) {
    int n = a.size();
    for (int i = 0; i < n; ++i) 
        if (i < flip_bin[i]) std::swap(a[i], a[flip_bin[i]]);
    for (int bisector = 1; bisector < n; bisector <<= 1) {
        long long ai = fastpow(inv ? Ginv : G, (P - 1) / (bisector << 1));
        for (int i = 0; i < n; i += (bisector << 1)) {
            long long multiplier = 1;
            for (int j = 0; j < bisector; ++j) {
                long long a0 = a[i + j], a1 = (multiplier * a[i + j + bisector]) % P;
                a[i + j] = (a0 + a1) % P;
                a[i + j + bisector] = (P + a0 - a1) % P;
                multiplier = (multiplier * ai) % P;
            }
        }
    }
}

/*
8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555544444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444333333333333333333333333333333333333333333333333222222222222222222222222222222222222222222222222222222222
5455555555555555555555555555555555555555555555555555555555555555555555555555555555666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888881111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111555555555555555555555555555555555
*/

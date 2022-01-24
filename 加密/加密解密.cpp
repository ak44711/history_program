#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<fstream> 
using namespace std;

string htob(string& s);
string btoh(string& s);
string SnorT(string& s1, string& s2);
int stoi(string& s);
string left_shift(string& s, int iteration_num);
string getIP(string& s);
string PC1(string& s);
string PC2(string& s);
string E(string& s);
string S1(string& s);
string S2(string& s);
string S3(string& s);
string S4(string& s);
string S5(string& s);
string S6(string& s);
string S7(string& s);
string S8(string& s);
string P(string& s);
string IP1(string& s);
string f(string tr, string Kn);
vector<string> get_subkeys(string& K0); 
string encryption(string& m, vector<string>& keys);
string decryption(string& m, vector<string>& keys);
string chtoh(char c) {
	int c2 = c & 0x0f;
	int c1 = c >> 4;
	unordered_map<int, char> m = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, 
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, 
		{8, '8'}, {9, '9'}, {10, 'a'}, {11, 'b'}, 
		{12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}
	};
	string t;
	t += m[c1];
	t += m[c2];
	return t; 
}
string htoch(string& s) {
	unordered_map<char, int> m = {
		{'0', 0}, {'1',1}, {'2',2}, {'3',3}, 
		{'4',4}, {'5',5}, {'6',6}, {'7',7}, 
		{'8',8}, {'9',9}, {'a',10}, {'b',11}, 
		{'c',12}, {'d',13}, {'e',14}, {'f',15}
	};
	string t;
	for(int i = 0; i < s.size(); i+=2) {
		int t1 = m[s[i]];
		int t2 = m[s[i + 1]];
		t += (char)(t1 * 16 + t2);
	}
	return t;
}
/*
https://blog.csdn.net/z784561257/article/details/78174106?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163517310716780269833844%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=163517310716780269833844&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~hot_rank-5-78174106.first_rank_v2_pc_rank_v29&utm_term=des&spm=1018.2226.3001.4187

02468aceeca86420
0f1571c947d9e859
da02ce3a89ecac3b
*/
/**********************************************************************************/
int main() {
	std::ios::sync_with_stdio(false);
	string K;
	cout << "请输入密钥" << endl;
	cin >> K; 
	vector<string> subkeys = get_subkeys(K);
	//K是64位原密钥 
	ifstream is("1.txt");
	ofstream os("2.txt");
	char str[10];
	
	while((is.read(str, 8) )){
		string s;
		for(int i = 0; i < 8; i++) {
			s += chtoh(str[i]);
		}
		if(s.size() < 8) {
			s = s + string(8-s.size(), '0');
			
			os << encryption(s, subkeys);
			break;
		}
		os << encryption(s, subkeys);
	}
	os.close();
	is.close();
	is.open("2.txt");
	
	is.read(str, 16);
	
	while((is.read(str, 16))) {
		string s(str);
		s += string(16 - s.size(), '0');
		string u = decryption(s, subkeys);
		cout << htoch(u);
		break;
		//cout << s << '-';
		string u = decryption(s, subkeys);
		cout << htoch(u);
	}
	return 0;
}

string decryption(string& m, vector<string>& keys){
	//十六进制转二进制 
	m = htob(m);
	//m1 = IP(m)
	string m1 = getIP(m);
	//L0是m1的左，R0是m1的右一半 
	string L0 = m1.substr(0, 32);
	string R0 = m1.substr(32,32);	
	
	string tl = L0;
	string tr = R0;
	string Ln, Rn;
	for(int i = 0; i < 16; i++) {

		Ln = tr;
		string tf = f(tr, keys[16 - i - 1]);
		Rn = SnorT(tl, tf);
		tl = Ln;
		tr = Rn;
	}
	string t = Rn + Ln;
	t = IP1(t);
	t = btoh(t);
	return t;
}

string encryption(string& m, vector<string>& keys){
	//十六进制转二进制 
	m = htob(m);
	//m1 = IP(m)
	string m1 = getIP(m);
	//L0是m1的左，R0是m1的右一半 
	string L0 = m1.substr(0, 32);
	string R0 = m1.substr(32,32);	
	
	string tl = L0;
	string tr = R0;
	string Ln, Rn;
	for(int i = 0; i < 16; i++) {
		//Ln = Rn-1
		//Rn = Ln-1 + f(Rn-1,Kn)
		Ln = tr;
		string tf = f(tr, keys[i]);
		Rn = SnorT(tl, tf);
		tl = Ln;
		tr = Rn;
	}
	string t = Rn + Ln;
	t = IP1(t);
	t = btoh(t);
	return t;
}

vector<string> get_subkeys(string& K) {
	vector<string> ans;
	//十六进制转二进制
	K = htob(K); 
	//将K进行PC1操作得到56位新密钥K0
	string K0 = PC1(K); 
	
	string tk = K0;

	for(int i = 0; i < 16; i++) {
		//CnDn是由Cn-1Dn-1左移操作得到的 
		string CnDn = left_shift(tk, i);
		//新密钥Kn由CnDn执行PC2得到的 
		string Kn = PC2(CnDn);
		ans.push_back(Kn);
		tk = CnDn;
	}
	return ans;
}

string S1(string& s) {
	int arr[][16] = {
		{14,  4,  13  ,1 ,  2 ,15  ,11 , 8  , 3 ,10  , 6, 12 ,  5 , 9   ,0,  7},
		{0, 15,   7 , 4 , 14,  2 , 13 , 1  ,10 , 6 , 12, 11 ,  9,  5  , 3,  8},
		{4,  1 , 14 , 8 , 13,  6 ,  2 ,11 , 15, 12 ,  9,  7 ,  3 ,10  , 5 , 0},
		{15, 12 ,  8 , 2,   4 , 9  , 1 , 7  , 5 ,11 ,  3 ,14 , 10,  0  , 6, 13}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	//模拟10进制转二进制的除法 
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	//不够位数前面补0 
	t = string(4-t.size(), '0') + t;
	return t;
}
string S2(string& s){
	int arr[][16] = {
		{15 , 1  , 8, 14 ,  6, 11  , 3 , 4  , 9 , 7 ,  2 ,13 , 12 , 0 ,  5 ,10},
		{3, 13  , 4  ,7 , 15  ,2 ,  8 ,14 , 12 , 0  , 1 ,10  , 6  ,9 , 11 , 5},
		{0 ,14 ,  7 ,11 , 10  ,4 , 13 , 1 ,  5 , 8  ,12 , 6  , 9  ,3  , 2 ,15},
		{13 , 8 , 10 , 1 ,  3 ,15,   4 , 2 , 11 , 6  , 7 ,12 ,  0 , 5 , 14 , 9}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}
string S3(string& s){
	int arr[][16] = {
		{10,  0  , 9 ,14  , 6 , 3  ,15 , 5   ,1 ,13 , 12 , 7 , 11  ,4 ,  2 , 8},
		{13 , 7  , 0 , 9 ,  3 , 4  , 6 ,10  , 2,  8 ,  5 ,14 , 12 ,11 , 15 , 1},
		{13 , 6  , 4,  9 ,  8, 15 ,  3 , 0 , 11 , 1  , 2 ,12  , 5 ,10 , 14 , 7},
		{1 ,10  ,13 , 0  , 6 , 9  , 8 , 7  , 4 ,15 , 14 , 3  ,11 , 5  , 2 ,12}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}
string S4(string& s){
	int arr[][16] = {
		{7 ,13  ,14 , 3 ,  0  ,6  , 9 ,10  , 1 , 2 ,  8  ,5  ,11 ,12 ,  4 ,15},
		{13,  8 , 11 , 5 ,  6 ,15 ,  0 , 3 ,  4 , 7 ,  2, 12 ,  1, 10 , 14 , 9},
		{10 , 6 ,  9 , 0 , 12, 11 ,  7 ,13 , 15 , 1 ,  3, 14 ,  5 , 2 ,  8 , 4},
		{3 ,15  , 0 , 6 , 10 , 1 , 13 , 8  , 9 , 4  , 5 ,11  ,12 , 7  , 2 ,14}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}
string S5(string& s){
	int arr[][16] = {
		{2 ,12  , 4  ,1  , 7 ,10,  11  ,6  , 8  ,5   ,3 ,15 , 13 , 0 , 14 , 9},
		{14 ,11  , 2 ,12 ,  4,  7 , 13,  1 ,  5 , 0 , 15, 10 ,  3 , 9 ,  8 , 6},
		{4  ,2   ,1 ,11  ,10 ,13 ,  7 , 8 , 15 , 9  ,12 , 5  , 6 , 3  , 0 ,14},
		{11 , 8 , 12 , 7 ,  1, 14 ,  2 ,13 ,  6 ,15  , 0 , 9 , 10  ,4  , 5 , 3}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}
string S6(string& s){
	int arr[][16] = {
		{12 , 1  ,10 ,15  , 9 , 2  , 6 , 8 ,  0 ,13,   3  ,4 , 14,  7 ,  5 ,11},
		{10 ,15  , 4 , 2 ,  7 ,12  , 9 , 5 ,  6 , 1 , 13 ,14 ,  0 ,11 ,  3 , 8},
		{ 9 ,14 , 15 , 5  , 2  ,8 , 12,  3 ,  7 , 0 ,  4 ,10 ,  1, 13 , 11,  6},
		{ 4 , 3  , 2 ,12  , 9 , 5 , 15, 10 , 11 ,14,   1 , 7 ,  6,  0 ,  8, 13}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}

string S7(string& s){
	int arr[][16] = {
		{ 4 ,11   ,2 ,14 , 15 , 0  , 8, 13 ,  3 ,12 ,  9 , 7  , 5 ,10 ,  6,  1},
		{13 , 0 , 11 , 7 ,  4 , 9  , 1 ,10 , 14 , 3 ,  5 ,12  , 2 ,15  , 8 , 6},
		{ 1 , 4 , 11 ,13 , 12 , 3  , 7 ,14 , 10 ,15 ,  6,  8  , 0,  5 ,  9 , 2},
		{6 ,11  ,13 , 8  , 1  ,4 , 10 , 7  , 9  ,5  , 0 ,15  ,14 , 2  , 3 ,12}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}

string S8(string& s){
	int arr[][16] = {
		{13 , 2 ,  8 , 4 ,  6, 15  ,11 , 1 , 10,  9  , 3 ,14 ,  5 , 0,  12 , 7},
		{1 ,15  ,13 , 8 , 10,  3  , 7  ,4 , 12 , 5  , 6 ,11 ,  0 ,14  , 9,  2},
		{7 ,11  , 4 , 1 ,  9 ,12 , 14 , 2 ,  0 , 6 , 10 ,13 , 15 , 3  , 5 , 8},
		{2 , 1 , 14 , 7  , 4 ,10  , 8 ,13 , 15, 12  , 9 , 0 ,  3 , 5  , 6 ,11}
	};
	string s1;
	s1 += s[0];
	s1 += s[5];
	string s2 = s.substr(1, 4);
	int row = stoi(s1);
	int col = stoi(s2);
	int c = arr[row][col];
	string t;
	while(c > 0) {
		t = to_string(c % 2) + t;
		c /= 2;
	}
	t = string(4-t.size(), '0') + t;
	return t;
}

string P(string& s) {
	int table[] = {
		16  , 7 , 20,  21,
        29 , 12,  28,  17,
        1  ,15 , 23 , 26,
        5 , 18 , 31  ,10,
        2  , 8 , 24  ,14,
        32 , 27 ,  3 ,  9,
        19 , 13 , 30  , 6,
        22 , 11  , 4 , 25		
	};
	string t;
	for(int i = 0; i < 32; i++) {
		t += s[table[i] - 1];
	}
	return t;
}

string htob(string& s) {
	unordered_map<char, string> m = {
		{'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"}, 
		{'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"}, 
		{'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"}, 
		{'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}
	}; 
	string t;
	for(int i = 0; i < s.size(); i++) {
		if(isupper(s[i])) s[i] = s[i] - ('A' - 'a');
		t += m[s[i]];
	}
	return t;
}

string btoh(string& s) {
	unordered_map<string, char> m = {
		{"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'}, 
		{"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'}, 
		{"1000", '8'}, {"1001", '9'}, {"1010", 'a'}, {"1011", 'b'}, 
		{"1100", 'c'}, {"1101", 'd'}, {"1110", 'e'}, {"1111", 'f'}
	};
	string t;
	for(int i = 0; i < s.size(); i += 4) {
		t += m[s.substr(i, 4)];
	}
	return t; 
}

string getIP(string& s) {
	string t;
	for(int i = 58; i > 0; i -= 8) t += s[i - 1];
	for(int i = 60; i > 0; i -= 8) t += s[i - 1];
	for(int i = 62; i > 0; i -= 8) t += s[i - 1];
	for(int i = 64; i > 0; i -= 8) t += s[i - 1];
	for(int i = 57; i > 0; i -= 8) t += s[i - 1];
	for(int i = 59; i > 0; i -= 8) t += s[i - 1];
	for(int i = 61; i > 0; i -= 8) t += s[i - 1];
	for(int i = 63; i > 0; i -= 8) t += s[i - 1];
	return t;
}

string PC1(string& s) {
	string t;
	int num = 57;
	for(int i = 0; i < 28; i++) {
		t += s[num - 1];
		num = (num - 8 + 65) % 65;
	}
	num = 63;
	for(int i = 0; i < 24; i++) {
		t += s[num - 1];
		num = (num - 8 + 63) % 63;
	}
	num = 28;
	for(int i = 0; i < 4; i++) {
		t += s[num - 1];
		num = num - 8;
	}
	return t;
}

string left_shift(string& s, int iteration_num) {
	string t;
	int left_shift_num[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	string s1 = s.substr(0, 28);
	string s2 = s.substr(28,28);
	int n = left_shift_num[iteration_num];//需要左移的次数 
	string t1;
	t1 += s1.substr(n, 28 - n);
	t1 += s1.substr(0, n);
	string t2 = s2.substr(n, 28 - n) + s2.substr(0, n);
	return t1 + t2;
} 

string PC2(string& s) {
	string t;
	int table[60] = {
		14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
	};
	for(int i = 0; i < 48; i++) {
		t += s[table[i] - 1];
	}
	return t;
}

string E(string& s) {
	int table[] = {
		32,1,2,3,4,5,
		4,5,6,7,8,9,
		8,9,10,11,12,13,
		12,13,14,15,16,17,
		16,17,18,19,20,21,
		20,21,22,23,24,25,
		24,25,26,27,28,29,
		28,29,30,31,32,1
	};
	string t;
	for(int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
		t += s[table[i] - 1];
	}
	return t;
}

string IP1(string& s) {
	int table[] = {
		40  ,   8 ,  48  ,  16 ,   56,   24,    64,   32,
        39  ,   7 ,  47  ,  15 ,   55,   23,    63,   31,
    	38  ,   6  , 46  ,  14 ,   54,   22,    62,   30,
        37  ,   5  , 45  ,  13 ,   53,   21,    61,   29,
        36  ,   4  , 44  ,  12 ,   52,   20,    60,   28,
        35  ,   3  , 43  ,  11 ,   51,   19,    59,   27,
        34  ,   2  , 42  ,  10 ,   50,   18,    58,   26,
        33  ,   1  , 41 ,    9 ,   49,   17,    57,   25
	};
	string t;
	for(int i = 0; i < 64; i++) {
		t += s[table[i] - 1];
	}
	return t;
}
int stoi(string& s) {
	int t = 0;
	for(int i = 0; i < s.size(); i++) {
		t = t * 2 + s[i] - '0';
	}
	return t; 
}
string SnorT(string& s1, string& s2) {
	string t;
	for(int i = 0; i < s1.size(); i++){
		t += s1[i] == s2[i] ? '0' : '1';
	}
	return t;
}


string f(string tr, string Kn) {
	string ER = E(tr);
	string t = SnorT(ER, Kn);
	string s1 = t.substr(0, 6);
	string s2 = t.substr(6, 6);
	string s3 = t.substr(12, 6);
	string s4 = t.substr(18, 6);
	string s5 = t.substr(24, 6);
	string s6 = t.substr(30, 6);
	string s7 = t.substr(36, 6);
	string s8 = t.substr(42, 6);
	
	s1 = S1(s1);
	s2 = S2(s2);
	s3 = S3(s3);
	s4 = S4(s4);
	s5 = S5(s5);
	s6 = S6(s6);
	s7 = S7(s7);
	s8 = S8(s8);
	t = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;
	return P(t);
}

#include<iostream>
#include<stack>
#include<cctype>
#include<unordered_map>
using namespace std; 

/*
读取一个字符
	如果是数字，继续读，直到不是字符
	如果是运算符，和栈顶比较
		如果比栈顶优先级高，符号直接入栈
		如果不是，数字栈栈顶两个元素进行符号栈顶的运算
字符产读完为止			 
*/
// 1+1/2*2

float evaluate(string& s) {
	stack<char> op;
	stack<float> num;
	//运算符优先级 
	unordered_map<char, int> pri = {{'+',1}, {'-', 1}, {'*', 2} , {'/', 2}, {'=', 0}};
	s.push_back('+');
	op.push('=');
	int t = 0; 
	int i = 0;
	while(i <= s.size() ) {
			//考虑到字符串s读取结束时 num栈中还有两个元素未计算完
		if(i < s.size() && isdigit(s[i])) {
			t = t * 10 + (s[i] - '0');
		}else{
			if(i < s.size() )num.push((float)t);
			t = 0;
			char preop = op.top();
			//有两个操作符并且优先级小于等于栈顶符号 
			if(num.size() > 1 && pri[s[i]] <= pri[preop] || i == s.size()) {
				//栈顶元素退栈 
				op.pop();
				//取出两个数
				float a = num.top();
				num.pop();
				float b = num.top();
				num.pop(); 
				//计算 
				if(preop == '+') {
					num.push(a + b);
				}else if(preop == '-') {
					num.push(b - a);
				}else if(preop == '*') {
					num.push(a * b);
				}else if(preop == '/') {
					num.push(b / a);
				}
			}
			op.push(s[i]);	
		}
		i++;
	}
	return num.top();
}

int main() {
	string s;
	getline(cin, s);
	//1+2*3
	
	cout << evaluate(s) << endl;
	
}

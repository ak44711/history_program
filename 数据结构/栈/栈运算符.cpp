#include<iostream>
#include<stack>
#include<cctype>
#include<unordered_map>
using namespace std; 

/*
��ȡһ���ַ�
	��������֣���������ֱ�������ַ�
	��������������ջ���Ƚ�
		�����ջ�����ȼ��ߣ�����ֱ����ջ
		������ǣ�����ջջ������Ԫ�ؽ��з���ջ��������
�ַ�������Ϊֹ			 
*/
// 1+1/2*2

float evaluate(string& s) {
	stack<char> op;
	stack<float> num;
	//��������ȼ� 
	unordered_map<char, int> pri = {{'+',1}, {'-', 1}, {'*', 2} , {'/', 2}, {'=', 0}};
	s.push_back('+');
	op.push('=');
	int t = 0; 
	int i = 0;
	while(i <= s.size() ) {
			//���ǵ��ַ���s��ȡ����ʱ numջ�л�������Ԫ��δ������
		if(i < s.size() && isdigit(s[i])) {
			t = t * 10 + (s[i] - '0');
		}else{
			if(i < s.size() )num.push((float)t);
			t = 0;
			char preop = op.top();
			//�������������������ȼ�С�ڵ���ջ������ 
			if(num.size() > 1 && pri[s[i]] <= pri[preop] || i == s.size()) {
				//ջ��Ԫ����ջ 
				op.pop();
				//ȡ��������
				float a = num.top();
				num.pop();
				float b = num.top();
				num.pop(); 
				//���� 
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

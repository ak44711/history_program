#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct node{
	string val;
	struct node* left;
	struct node* right;
}Node;

Node* create_fbi_tree(string s){
	Node* n = new Node[1];
	n ->val = s;
	if(s.size() == 1){
		n ->left = NULL;
		n ->right = NULL;
	}else{
		n ->left = create_fbi_tree(s.substr(0, s.size() / 2));
		n ->right = create_fbi_tree(s.substr(s.size() / 2, s.size() / 2));
	}
	return n;
}

char fbi(string s){
	bool c0 = false;
	bool c1 = false;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0'){
			c0 = true;
		}
		if(s[i] == '1'){
			c1 = true;
		}
	}
	if(c0 == true && c1 == true){
		return 'F';
	}else if(c0 == true && c1 == false){
		return 'B';
	}else if(c0 == false && c1 == true){
		return 'I';
	}
}

void later_travel(Node* t){
	if(t){
		later_travel(t ->left);
		later_travel(t ->right);
		cout << fbi(t ->val);
	}
}

int main() {
	/*string s;
	int n;
	cin >> n >> s;
	Node* t = create_fbi_tree(s);
	later_travel(t);
	cout << endl;
	*/
	cout << sizeof(bool) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(char) << endl;
	return 0;
}

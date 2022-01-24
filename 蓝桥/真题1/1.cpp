#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<fstream>
using namespace std;
struct Tree{
public:
	string val;
	vector<Tree*> next;
public:
	Tree(){}
	Tree(string val) {this->val = val;}
	Tree* findNode(string val) {
		if(this ->val == val) return this;
		queue<Tree*> q;
		for(int i = 0; i < next.size(); i++) {
			q.push(next[i]); 
		}
		while(!q.empty()) {
			Tree* t = q.front();
			q.pop();
			if(t->val == val) return t;
			for(int i = 0; i < t->next.size(); i++) {
				q.push(t->next[i]);
			}
		}
		return NULL;
	}
	void insertNode(string parent, string val) {
		Tree* node = findNode(parent);
		if(node == NULL) {
			cout << "没有该父节点" << endl; 
		}else {
			Tree* newNode = new Tree(val);
			node->next.push_back(newNode);
		}
	}
};

struct BTree{
public:
	string val;
	BTree* left;
	BTree* right;
public:
	BTree(){
		left = NULL;
		right = NULL;
	}
	BTree(string val) {
		this->left = NULL;
		this->right = NULL;
		this->val = val;
	}
};

Tree* createTreeByKey() {
	Tree* root = NULL;
	cout << "创建规则：先输入父节点（根据val确认，根节点的父节点为0， 停止输入为-1）再输入值" << endl;
	while(true) {
		cout << "请输入父节点" << endl;
		string parent;
		string val;
		cin >> parent;
		if(parent == "-1") {
			cout << "结束创建" << endl;
			break; 
		}else if(parent == "0") {
			cout << "请输入值：";
			cin >> val;
			root = new Tree(val);
		}else{
			cout << "请输入值：";
			cin >> val;
			root->insertNode(parent, val);
		}
	}
	return root;
}

void dfs_travel(Tree* root) {
	if(root == NULL) return;
	cout << root->val << " ";
	for(int i = 0; i < root->next.size(); i++) {
		dfs_travel(root->next[i]);
	}
}
void bfs_travel(Tree* root) {
	if(root == NULL) return;
	queue<Tree*> q;
	q.push(root);
	while(!q.empty()) {
		Tree* t = q.front();
		cout << t->val << " ";
		q.pop();
		for(int i = 0; i < t->next.size(); i++) {
			q.push(t->next[i]);
		}
	}
}
Tree* createTreeByFile(){
	Tree* root;
	string filename;
	cout << "请输入文件名：" << endl;
	cin >> filename;
	ifstream myfile(filename.c_str()); 
	string parent;
	string val;
    if (!myfile.is_open()) 
    { 
        cout << "未成功打开文件" << endl; 
    }
	while(getline(myfile, parent)){
		if(getline(myfile, val)) {
			if(parent == "-1") {
				break; 
			}else if(parent == "0") {
				root = new Tree(val);
			}else{
				root->insertNode(parent, val);
			}
		}
	}
	
	return root;
}

BTree* transferBT(Tree* root, Tree* parent, int index) {
	if(root == NULL) return NULL;
	BTree* ans = new BTree(root ->val);
	cout << root ->val << endl;
	if(root ->next.size() > 0)ans ->left = transferBT(root->next[0], root, 0);
	 
	if(parent != NULL) ans ->right = index < parent->next.size() - 1? transferBT(parent->next[index+1], parent, index + 1) : NULL;
	
	return ans;
}

void pre_print(BTree* root) {
	if(root == NULL) return;
	cout << root ->val << " ";
	pre_print(root ->left);
	pre_print(root->right);
}
void mid_print(BTree* root) {
	if(root == NULL) return;
	
	mid_print(root ->left);
	cout << root ->val << " ";
	mid_print(root ->right);
}
void pos_print(BTree* root) {
	if(root == NULL) return;
	pos_print(root ->left);
	pos_print(root ->right);
	cout << root ->val << " ";
}
int main() {
	Tree* root = NULL;
	BTree* broot = NULL;
	int opt = -1;
	cout << "[1] create Tree by Key\n[2] create Tree by File\n[3] deep first print\n" << 
			"[4] breadth print\n\n"
			<<"[8] tranfer to bintree\n[0] Quit\n"<<endl;
	while(opt != 0) {
		cin >> opt;
		switch(opt) {
			case 1: root = createTreeByKey(); cout << "创建结束" << endl; break;
			case 2: root = createTreeByFile(); cout << "创建结束" << endl;  break;
			case 3:	cout << "dfs: "; dfs_travel(root); cout << endl; break;
			case 4: cout << "bfs: "; bfs_travel(root); cout << endl; break;
			case 5: cout << "transfer to binTree..." << endl;; broot = transferBT(root, NULL, 0); cout << "转换结束" << endl; break;
			case 6: cout << "preorder print : "; pre_print(broot); cout << endl; break;
			case 7: cout << "midorder print : "; mid_print(broot); cout << endl; break;
			case 8: cout << "posorder print : "; pos_print(broot); cout << endl; break;
		}
	}	
}

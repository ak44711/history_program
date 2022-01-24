/*二叉树的代码
*2.树的遍历（递归、非递归） 
*3.树的深度
*4.叶子数量 
*/
#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#include<fstream> 
using namespace std;
#define ElemType int

/******* 结点结构 ********/
class BiNode{
public:
	ElemType data;
	BiNode* lchild;
	BiNode* rchild;
public:
	BiNode(){
		this->lchild = NULL;
		this->rchild = NULL;
	}
};
	
/******* 递归遍历 ********/
void PreTravel(BiNode* root) {
	if(!root) return;
	cout << root->data << " ";
	PreTravel(root->lchild);
	PreTravel(root->rchild);
}

void MidTravel(BiNode* root) {
	if(!root) return;
	MidTravel(root->lchild);
	cout << root->data << " ";
	MidTravel(root->rchild);
}

void PosTravel(BiNode* root) {
	if(!root) return;
	PosTravel(root->lchild);
	PosTravel(root->rchild);
	cout << root->data << " ";
}

/******* 迭代遍历 ********/
void PreTravel2(BiNode* root) {
	if(!root) return;
	stack<BiNode*> stk;
	stk.push(root);
	while(!stk.empty()) {
		BiNode* temp = stk.top();
		stk.pop();
		cout << temp->data << " ";
		if(temp->rchild) stk.push(temp->rchild);
		if(temp->lchild) stk.push(temp->lchild);
	}
}

void MidTravel2(BiNode* root) {
	if(!root) return;
	stack<BiNode*> stk;
	while(root || !stk.empty()) {
		while(root) {
			//左子树全部入栈 
			stk.push(root);
			root = root->lchild; 
		}
		root = stk.top(); 
		stk.pop();
		cout << root->data << " ";
		root = root->rchild; 
	}
	
}

void PosTravel2(BiNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<BiNode *> stk;
    BiNode *prev = nullptr;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.emplace(root);
            root = root->lchild;
        }
        root = stk.top();
        stk.pop();
        if (root->rchild == nullptr || root->rchild == prev) {
            cout << root->data << " ";
            prev = root;
            root = nullptr;
        } else {
            stk.emplace(root);
            root = root->rchild;
        }
    }
}

void LevelTravel(BiNode* root) {
	if(!root) return;
	queue<BiNode*> que;
	que.push(root);
	while(!que.empty()) {
		BiNode* temp = que.front();
		que.pop();
		cout << temp->data << " ";
		if(temp->lchild) que.push(temp->lchild);
		if(temp->rchild) que.push(temp->rchild);
	}
}

/******* 树的深度 ********/
int Depth(BiNode* root) {
	if(!root) return 0;
	return max(Depth(root->lchild), Depth(root->rchild)) + 1;
}

/******* 叶子数量 ********/
int Leaves(BiNode* root) {
	if(!root) return 0;
	if(!root->lchild && !root->rchild) return 1;
	return Leaves(root->lchild) + Leaves(root->rchild);
}


int main() {
	ifstream is("1.txt");
	string t;
	getline(is, t);
	cout << t << endl;
	char c = is.get(); 
	cout << c <<endl;
	/*
	BiNode tree[100];
	int n = 20;
	for(int i = 0; i < n; i++) {
		tree[i].data = i;
		if(i * 2 + 1 < n){
			tree[i].lchild = &tree[i * 2 + 1];
		}
		if(i * 2 + 2 < n){
			tree[i].rchild = &tree[i * 2 + 2];
		}
	}
	cout << "先序递归："; PreTravel(&tree[0]); cout << endl;
	cout << "先序迭代："; PreTravel2(&tree[0]); cout << endl << endl;
	cout << "中序递归："; MidTravel(&tree[0]); cout << endl;
	cout << "中序迭代："; MidTravel2(&tree[0]); cout << endl << endl;
	cout << "后序递归："; PosTravel2(&tree[0]); cout << endl << endl;
	cout << "后序迭代："; PosTravel2(&tree[0]); cout << endl << endl;
	
	cout << "层次："; LevelTravel(&tree[0]); cout << endl;
	cout << "深度：" << Depth(&tree[0]) << endl;
	cout << "叶子数量：" << Leaves(&tree[0]) << endl;
	*/
	return 0;
}

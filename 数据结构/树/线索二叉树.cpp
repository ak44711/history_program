#include<iostream>
using namespace std;
struct node{
	char val;
	//true代表普通，false代表线索 
	bool ltag = true;
	bool rtag = true;
	node* left;
	node* right;
	node() : ltag(true), rtag(true), left(NULL), right(NULL) {}
}; 

void PreTravel(node* root) {
	if(!root) return;
	cout << root->val << " ";
	PreTravel(root->left);
	PreTravel(root->right);
}

void MidTravel(node* root) {
	if(!root) return;
	MidTravel(root->left);
	cout << root->val << " ";
	MidTravel(root->right);
}

void PosTravel(node* root) {
	if(!root) return;
	PosTravel(root->left);
	PosTravel(root->right);
	cout << root->val << " ";
}
//DBEAC
void cue(node*& root, node*& pre) {
	if(!root) return;
	cue(root->left, pre);
	
	if(!root->left) {
		root->ltag = false;
		root->left = pre;
	}
	
	if(!root->right) {
		pre->right = root;
		pre->rtag = false;
	}
	
	cue(root->right, pre);
}

int main() {
	int n = 5;
	node* tree = new node[n];
	for(int i = 0; i < n; i++) {
		tree[i].val = i + 'A';
	}
	for(int i = 0; i < n; i++) {
		if(i * 2 + 1 < n) tree[i].left = &tree[i * 2 + 1];
		if(i * 2 + 2 < n) tree[i].right = &tree[i * 2 + 2];
	}
	node* pre = tree;
	MidTravel(tree);
	cue(tree, pre);
	return 0;
} 

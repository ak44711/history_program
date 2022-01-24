#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
struct node{
	int val;
	node *left;
	node *right;
	node() : left(NULL), right(NULL){}
	node(int x) : val(x), left(NULL), right(NULL){}
};

node *insert(node* root, int x) {
	if(!root) root = new node(x);
	else if(x < root->val) {
		root->left = insert(root->left, x);
	}else{
		root->right = insert(root->right, x);
	}
	return root;
}

node *find(node* root, int x) {
	if(root == NULL) return NULL;
	if(x == root->val) return root;
	if(x < root->val) find(root->left, x);
	if(x > root->val) find(root->right, x);
}

node *erase(node* root, int x) {
	//if root is null nothing to do
	if(root == NULL) return root;
	else if(x < root->val) root->left = erase(root->left, x);
	else if(x > root->val) root->right = erase(root->right, x);
	else if(x == root->val){
		//if root if leave
		if(root->left == NULL && root->right == NULL) {
			delete(root);
			return NULL; 
		}else if(root->right == NULL) {
			node* temp = root;
			root = root->left;
			delete(temp);
			return root;
		}else if(root->left == NULL) {
			node* temp = root;
			root = root->right;
			delete(temp);
			return root;
		}else{
			/*root has two childs, 
				you can use max_node from left_sub_tree or min_node from right_sub_tree
					replace root' val, then erase the node you selected
				*/
			node* temp = root->left;
			while(temp->right != NULL) temp = temp->right;
			root->val = temp->val;
			root->left = erase(root->left, temp->val);
			
		}	
	}
	return root;
}
void mid(node* root) {
	if(root == NULL) return;
	mid(root->left);
	cout << root->val << " ";
	mid(root->right);
}
int main() {
	node *root = NULL;
	srand((unsigned)time(NULL));
	int a[] = {9,5,4,6,7,8,3,1};
	int n = sizeof(a) / sizeof(a[0]);
	for(int i = 0; i < n; i++) {
		root = insert(root, a[i]);
		mid(root);cout << endl;
	}
	root = erase(root, 1); mid(root);cout << endl;
	return 0;
} 

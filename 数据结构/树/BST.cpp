#include<iostream>
using namespace std;

struct bst{
	bst* left;
	bst* right;
	int val;
};
bst* search(bst* root, int val) {
	if(!root || root->val == val) return root;
	if(val < root->val) return search(root->left, val);
	return search(root->right, val);
}
bst* delete_node(bst* root, int val) {
	if(root == NULL) return root;
	if(val < root->val) root->left = delete_node(root->left, val);
	else if(val > root->val) root->right = delete_node(root->right, val);
	//找到需要被删除的的节点 
	else{
		if(!root->left && !root->right) {//删除叶子节点 
			free(root);
			return NULL;
		}else if(!root->left) {//没有左子树有右子树 
			bst* p = root->right;
			free(root);
			return p;
		}else if(!root->right) {//没有右子树有左子树 
			bst* p = root->left;
			free(root);
			return p;
		}
		//有左子树也有右子树
		//找到右子树中最小的节点p 
		bst*p = root->right;
		while(p->left)
			p = p->left;
		//p节点的左子树变成root的左子树 
		bst* q = root;
		p->left = root->right;
		//root更新成root的右子树 
		root = root->right;
		//删除原root 
		free(q);
	}
	//返回root 
	return root;
} 
bst* insert(bst* root, int val){
    if(root == NULL) {
        bst* node = (bst*) malloc(sizeof(bst));
        node->left = NULL;
        node->right = NULL;
        node->val = val;
        return node;
    }
    //允许重复删除这句 
    if(root->val == val) return root;
    if(root->val > val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}
void mid(bst* root) {
	if(!root) return;
	mid(root->left);
	cout << root->val << " ";
	mid(root->right);
} 

int main() {
	int arr[] =  {1,3,5,7,8,65,4,3,2,4,5,2,4,3,4};
	bst* root = NULL;
	bst* p;
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		root = insert(root, arr[i]);mid(root);cout << endl;
	}
	//一棵树是是二叉排序树 当且仅当 中序遍历结果为有序的 
	root = insert(root, 1);mid(root);cout << endl;
	 
	root = insert(root, 2);mid(root);cout << endl;
	
	root = insert(root, 3);mid(root);cout << endl;
	
	root = delete_node(root, 2);
	mid(root);cout << endl;
	
	root = insert(root, 2);mid(root);cout << endl;

	root = insert(root, 4);mid(root);cout << endl;
	
	root = insert(root, 6);mid(root);cout << endl;
	
	root = delete_node(root, -100);mid(root);cout << endl;
	
	p = search(root, 6); if(p) cout << "有6" << endl;  else cout << "无6" << endl;
	
	root = insert(root, 7);mid(root);cout << endl;
	
	root = delete_node(root, 6);mid(root);cout << endl;

	root = insert(root, -1);mid(root);cout << endl;
	
	p = search(root, 6); if(p) cout << "有6" << endl;  else cout << "无6" << endl;
	
	return 0;
}

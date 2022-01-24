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
	//�ҵ���Ҫ��ɾ���ĵĽڵ� 
	else{
		if(!root->left && !root->right) {//ɾ��Ҷ�ӽڵ� 
			free(root);
			return NULL;
		}else if(!root->left) {//û���������������� 
			bst* p = root->right;
			free(root);
			return p;
		}else if(!root->right) {//û���������������� 
			bst* p = root->left;
			free(root);
			return p;
		}
		//��������Ҳ��������
		//�ҵ�����������С�Ľڵ�p 
		bst*p = root->right;
		while(p->left)
			p = p->left;
		//p�ڵ�����������root�������� 
		bst* q = root;
		p->left = root->right;
		//root���³�root�������� 
		root = root->right;
		//ɾ��ԭroot 
		free(q);
	}
	//����root 
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
    //�����ظ�ɾ����� 
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
	//һ�������Ƕ��������� ���ҽ��� ����������Ϊ����� 
	root = insert(root, 1);mid(root);cout << endl;
	 
	root = insert(root, 2);mid(root);cout << endl;
	
	root = insert(root, 3);mid(root);cout << endl;
	
	root = delete_node(root, 2);
	mid(root);cout << endl;
	
	root = insert(root, 2);mid(root);cout << endl;

	root = insert(root, 4);mid(root);cout << endl;
	
	root = insert(root, 6);mid(root);cout << endl;
	
	root = delete_node(root, -100);mid(root);cout << endl;
	
	p = search(root, 6); if(p) cout << "��6" << endl;  else cout << "��6" << endl;
	
	root = insert(root, 7);mid(root);cout << endl;
	
	root = delete_node(root, 6);mid(root);cout << endl;

	root = insert(root, -1);mid(root);cout << endl;
	
	p = search(root, 6); if(p) cout << "��6" << endl;  else cout << "��6" << endl;
	
	return 0;
}

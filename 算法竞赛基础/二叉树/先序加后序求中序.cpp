#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree{
	char val;
	struct tree* letf;
	struct tree* right;
}tree;
tree* create_tree(const char* pre, const char* mid, int beg1, int beg2, int n) {
	if(n <= 0) return NULL;
	tree* node = (tree*) malloc (sizeof(tree));
	node->val = pre[beg1];
	int i = 0;
	for(; mid[i + beg2] != pre[beg1]; i++);//判断了几次，就意味着左根节点左树的节点总树有多少个 
	node->letf = create_tree(pre, mid, beg1 + 1, beg2, i);
	node->right = create_tree(pre, mid, beg1 + i + 1, beg2 + i + 1, n - 1 - i);
	return node;
}
#define pre 0
#define mid 1
#define late 2 
void travel(tree* root, int type) {
	if(root == NULL) return;
	if(type == pre) printf("%c ", root->val);
	travel(root->letf, type);
	if(type == mid) printf("%c ", root->val);
	travel(root->right, type);
	if(type == late) printf("%c ", root->val); 
}
void _travel(tree* root, int type) {
	travel(root, type);
	printf("\n");
}
int main() {
	char pre_res[100] = "124735896";
	char mid_res[100] = "472185936";
	int len = strlen(pre_res);
	tree* root = create_tree(pre_res, mid_res, 0, 0, len);
	_travel(root, pre);
	_travel(root, mid);
	_travel(root, late);
	return 0;
}



#include<iostream>
#include<cstdlib>
using namespace std;
const int N=1e5+10;
int n;
struct node {
	int val;
	node* left, *right;
	node():left(NULL), right(NULL) {}
	node(int val):val(val),left(NULL), right(NULL) {}
};

node* arr[N];

void build_tree() {
	int t = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		if(t == 0) arr[i] = NULL;
		else{
			arr[i] = new node(t);
		}
	}
	for(int i = 0; i < n; i++) {
		if(arr[i]) {
			if(i * 2 + 1 < n) arr[i]->left = arr[i * 2 + 1];
			if(i * 2 + 2 < n) arr[i]->right = arr[i * 2 + 2];
		}
	}
}
void PreTravel(node* root) {
	if(!root) return;
	cout << root->val << " ";
	PreTravel(root->left);
	PreTravel(root->right);
}

int main() {
	scanf("%d", &n);
	build_tree();
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	PreTravel(arr[0]); 
}

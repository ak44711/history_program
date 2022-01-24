#include<iostream>
#include<cstdlib>
using namespace std;
struct tree{
	tree(int x) {
		left = NULL;
		right = NULL;
		val = x;
	}
	tree* left;
	tree* right;
	int val;
};
void insertTree(int x, tree* T) {
	if(x > T ->val) {
		if(T ->right == NULL) {
			tree* t = new tree(x);
			T ->right = t;
		}else {
			insertTree(x, T ->right);
		}
		return;
	}
	if(T ->left == NULL) {
		tree* t = new tree(x);
		T ->left = t;
	}else {
		insertTree(x, T ->left);
	}
}
int findDepth(tree* T) {
	if(T == NULL) return 0;
	return max(findDepth(T ->left), findDepth(T ->right)) + 1;
}
void count(tree* T, int d,int depth, int& returnDepth) {
	if(T == NULL) {
		return;
	}
	if(d > depth - 2) returnDepth++;
	count(T->left, d + 1, depth, returnDepth);
	count(T->right, d + 1, depth, returnDepth);
}
void midTravel(tree* T) {
	if(T == NULL) return;
	midTravel(T ->left);
	cout << T->val << " ";
	midTravel(T ->right);
} 
int main () {
	int N;
	cin >> N;
	int t;
	cin >> t;
	tree* root = new tree(t);
	for(int i = 1; i < N; i++) {
		cin >> t;
		insertTree(t, root);
	}
	//int depth = findDepth(root);
	//int cnt = 0;
	//count(root, 1, depth, cnt);
	//cout << cnt << endl;
	midTravel(root);
}

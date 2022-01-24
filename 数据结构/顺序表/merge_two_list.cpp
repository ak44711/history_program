#include<iostream>
using namespace std;
const int N = 1e5 + 10;
struct list{
	int val;
	struct list* next;
	list():next(NULL){}
};

struct list* create_list(int* arr, int len) {
	struct list* head = NULL, *pre, *p;
	for(int i = 0; i < len; i++) {
		p = (struct list*) malloc (sizeof(struct list));
		p->next = NULL;
		p->val = arr[i];
		
		if(i == 0) {
			head = p;
			pre = head;
		}else{
			pre->next = p;
			pre = p;
		}
	}
	return head;
}

void print_list(struct list* head) {
	while(head) {
		cout << head->val << " ";
		head = head->next; 
	}
	cout << endl;
}

list* merge(list* l1, list* l2) {
	list* head = NULL;
	list *p = NULL, *q = NULL;
	while(l1 && l2) {
		q = new list();
		if(l1->val < l2->val) {
			q->val = l1->val;
			l1 = l1->next;
		} else {
			q->val = l2->val;
			l2 = l2->next;
		}
		if(p == NULL) {
			p = q;
			head = q;
		}else{
			p->next = q;
			p = q;
		}
	}
	while(l1) {
		q = new list();
		q->val = l1->val;
		l1 = l1->next;
		if(p == NULL) {
			p = q;
			head = q;
		}else{
			p->next = q;
			p = q;
		}
	}
	while(l2) {
		q = new list();
		q->val = l2->val;
		l2 = l2->next;
		if(p == NULL) {
			p = q;
			head = q;
		}else{
			p->next = q;
			p = q;
		}
	}
	return head;
}

int main() {
	int arr1[] = {1,3,5,7,9};
	int arr2[] = {2,4,6,8,10};
	list* l1 = create_list(arr1, sizeof(arr1) / sizeof(arr1[0]));
	list* l2 = create_list(arr2, sizeof(arr2) / sizeof(arr2[0]));
	print_list(l1);
	print_list(l2);
	list* l3 = merge(l1, l2);
	print_list(l3);
	return 0;
} 

#include<iostream>
#include<stdlib.h>
#define ElementType char

using namespace std;

typedef struct linklist{
	ElementType data;
	struct linklist* next;
}linklist;

linklist* CreateList_Front() {
	linklist* head = NULL, *p;
	char ch;
	printf("请输入数据，以#接受\n"); 
	ch = getchar();
	while(ch != '#') {
		p = (linklist*)malloc(sizeof(linklist));
		p->next = head;
		p->data = ch;
		head = p;
		ch = getchar();
	}
	return head;
}

linklist* CreateList_Tail() {
	linklist* head = NULL;
	linklist* p, *q;
	char ch;
	printf("请输入数据，以#接受\n"); 
	ch = getchar();
	while(ch != '#') {
		q = (linklist*)malloc(sizeof(linklist));
		q->next = NULL;
		q->data = ch;
		
		if(head == NULL) {
			head = q;
		}else {
			p->next = q;
		}
		p = q;	
		ch = getchar();
	}
	return head;
}

linklist* Reverse(linklist* head){
	linklist* pre = NULL;
	linklist* next = head;
	while(head) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

linklist* Merge(linklist* l1, linklist* l2) {
	linklist* head = NULL, *p;
	while(l1 && l2) {
		if(l1->data < l2->data) {
			if(head == NULL) {
				head = l1;
				p = l1;
			}else{
				p->next = l1;
				p = p->next;
			}
			l1 = l1->next;
		}else{
			if(head == NULL) {
				head = l2;
				p = l2;
			}else{
				p->next = l2;
				p = p->next;
			}
			l2 = l2->next;
		}
	}
	if(l1) p->next = l1;
	else p->next = l2;
	return head;
}

void PrintList(linklist* head) {
	while(head) {
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	printf("create list1:\n");
	linklist* list1 = CreateList_Tail();
	PrintList(list1);
	
	getchar();//跳回车 
	
	printf("\ncreate list2:\n");
	linklist* list2 = CreateList_Tail();
	PrintList(list2);
	
	printf("\nmerge list1 and list2:\n");
	linklist* list3 = Merge(list1, list2);
	PrintList(list3);
	
	printf("\nreverse list3:\n");
	list3 = Reverse(list3);
	PrintList(list3);
	
	return 0;
} 

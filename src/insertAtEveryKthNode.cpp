/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K<1)
		return NULL;
	struct node *Head = head;
	for (int count = K; head != NULL; count--, head = head->next){
		if (count == 1){
			struct node *insert = (struct node *) malloc(sizeof(struct node *));
			insert->num = K;
			insert->next = head->next;
			head->next = insert;
			count = K + 2;
		}
	}
	return Head;
}
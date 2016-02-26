/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node * link = NULL;
	//struct node * newHead = head;
	for (struct node * newHead = head; head->next != NULL; head = newHead){
		newHead = head->next;
		head->next = link;
		link = head;
	}
	head->next = link;
	return head;

}

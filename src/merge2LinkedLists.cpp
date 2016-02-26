/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	//error cases
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *merge = (head1->num > head2->num) ? head2 : head1;
	head1 = (head1->num <= head2->num) ? head2 : head1;
	struct node *temp = merge;
	while (merge->next != NULL && head1->next != NULL){
		if (merge->next->num > head1->num){
			//insert the node when small
			head2 = head1->next;
			head1->next = merge->next;
			merge->next = head1;
			merge = head1;
			head1 = head2;
		}
		else
			//iter when node is bigger
			merge = merge->next;

	}
	while (merge->next != NULL)
		//move to end
		merge = merge->next;
	if (head1 != NULL){
		//add rest of nodes in head
		merge->next = head1;

	}
	return temp;
}

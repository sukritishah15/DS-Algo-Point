#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

void swap ( int* a, int* b )
{ int t = *a; *a = *b; *b = t; }

struct Node *lastNode(struct Node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}

struct Node* partition(struct Node *l, struct Node *h)
{
	int x = h->data;

	struct Node *i = l->prev;

	for (struct Node *j = l; j != h; j = j->next)
	{
		if (j->data <= x)
		{
			i = (i == NULL) ? l : i->next;

			swap(&(i->data), &(j->data));
		}
	}
	i = (i == NULL) ? l : i->next;
	swap(&(i->data), &(h->data));
	return i;
}

void _quickSort(struct Node* l, struct Node *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		struct Node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}

void quickSort(struct Node *head)
{
	struct Node *h = lastNode(head);

	_quickSort(head, h);
}

void printList(struct Node *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)
			malloc(sizeof(struct Node));
	new_node->data = new_data;

	new_node->prev = NULL;

	new_node->next = (*head_ref);

	if ((*head_ref) != NULL) (*head_ref)->prev = new_node ;

	(*head_ref) = new_node;
}

int main(int argc, char **argv)
{
	struct Node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	printf("Linked List before sorting \n");
	printList(a);

	quickSort(a);

	printf("Linked List after sorting \n");
	printList(a);

	return 0;
}

/*
Input:
30  3  4  20  5
Output:
3  4  5  20  30
/*
The worst case time complexity is O(n*n)
Space complexity is O(n)
*/

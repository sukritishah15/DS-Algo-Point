#include<stdio.h>
#include<stdlib.h>
 
//structure definition
struct list
{
	int info;
	struct list *next;
};
 
//Functions Prototypes
void create(struct list **, int);
void traverse(struct list *);
void insert_first(struct list **,int);
void insert_last(struct list **, int);
int count(struct list *);
void delete_first(struct list **);
void delete_last(struct list **);
void reverse(struct list **);
void del_node(struct list **, int);
void insert_after(struct list *, int, int);
void insert_before(struct list **, int, int);
 
//Main Function
int main()
{
int num, c, item,item2,item1;
	struct list *head=NULL;
	while(1)
	{
		//switch to display menu
		printf("1.Create\n2.Traverse\n3.Insert First\n4.Insert Last\n5.Delete First\n6.Delete Last\n7.Count\n8.Reverse\n9.Delete a node with specific element\n10.Insert a element before certain element\n11.Insert a element after certain element\n0.Exit\nYour Choice: ");
		scanf("%d",&c);
		switch(c)                                         	
		{
			case 1:
			  	printf("\nEnter the number of nodes: ");
				scanf("%d",&num);
				create(&head, num);
				break;
			                                	
			case 2:
			        traverse(head);
			        break;
			case 3:
			        printf("\nEnter the information for the node to be inserted: ");
			        scanf("%d",&item);
			        insert_first(&head,item);
			        break;
			
			case 4:
			        printf("\nEnter the information for the node to be inserted: ");
			        scanf("%d",&item);
			        insert_last(&head,item);
			        break;
			
			case 5:
			        delete_first(&head);
			        break;
			
			case 6:
			        delete_last(&head);
			        break;
		
			case 7:
	                printf("\nNumber of nodes: %d\n", count(head));
	                break;
			
			case 8:
	                reverse(&head);
	                break;
		                                
			case 9:
	                printf("\nEnter the element of node to delete: ");
	                scanf("%d",&item);
	                del_node(&head,item);
	                break;
		
			case 10:
		            printf("\nEnter the element of node before which you want to insert: ");
		            scanf("%d",&item1);
		            printf("\nEnter the value to insert: ");
		            scanf("%d",&item2);
		            insert_before(&head,item1,item2);
					break;
		
			case 11:
		            printf("\nEnter the element of node after which you want to insert: ");
		  			scanf("%d",&item1);
	                printf("\nEnter the value to insert: ");
	                scanf("%d",&item2);
	                insert_after(head,item1,item2);
					break;
		
			case 0: exit(0);
			default:
			        printf("\nWrong input. Please try again...");
		}       	
	}
	return(0);
}
 
//Function definition to create linked list
void create(struct list **phead, int num)
{
	struct list *temp,*newnode;
   	int item,i;
   	if(*phead != NULL)
   	{
      		printf("Already created");
      		return;
   	}
   	for(i=1;i<=num;i++)
   	{
		printf("Enter the information to be stored in a node: ");
		scanf("%d",&item);
		newnode=(struct list *)malloc(sizeof(struct list));
		newnode->info=item;
		newnode->next=NULL;

		if(*phead == NULL)
			*phead=newnode;
		else
			temp->next=newnode;

		temp=newnode;
    	}
    	return;

}
 
//Function definition to display linked list
void traverse(struct list *head)
{
	struct list *loc;
  	loc=head;

  	while(loc!=NULL)
	{
 		printf("%d ",loc->info);
 		loc=loc->next;
	}
	printf("\n");
}
 
//Function definition to insert element in first place
void insert_first(struct list **phead, int item)
{
	struct list *newnode;
  	newnode = (struct list *) malloc(sizeof(struct list));
  	newnode->info = item;
  	newnode->next = *phead;
  	*phead = newnode;
  	return; 
}
 
//Function definition to insert element in last place
void insert_last(struct list **head, int item)
{
	struct list  *loc, *newnode;
	newnode = (struct list *) malloc(sizeof(struct list));
  	newnode->info = item;
	newnode->next = NULL;
	loc=*head;

	while(loc->next!=NULL)
  	{
    		loc=loc->next;
  	}

	loc->next = newnode;
	return; 
}
 
//Function definition to count element in linked list
int count(struct list *head)
{
	int count=0;
	struct list *loc;
  	loc=head;
  	while(loc!=NULL)
  	{
		count+=1;
     		loc=loc->next;
  	}
	return count;
}

 
//Function definition to delete element in first place
void delete_first(struct list **phead)
{
	struct list *temp;

	if(*phead == NULL)
	{
		printf("\nEmpty List...Deletion is impossible....\n");
		return;
	}
	
	temp = *phead;
	*phead = (*phead)->next;	

	printf("\nInformation on deleted note is %d\n",temp->info);

	temp->next = NULL;
	free(temp);

	return;
}

 //Function definition to delete element in last place
void delete_last(struct list **phead)
{
	struct list *loc, *locp;
	if(*phead==NULL)
	{
		printf("\nEmpty List");
		return;
	}

	loc=*phead;
	locp=NULL;

	while(loc->next!=NULL)
	{
		locp=loc;
		loc=loc->next;
	}

	printf("\nInformation on deleted node is %d\n",loc->info);
	
	if(loc==*phead)
		*phead=loc->next;
	else
		locp->next=loc->next;
	
	free(loc);
}

//Function definition to reverse a linked list
void reverse(struct list **phead)
{
	struct list *locp, *loc, *locn;
	if(*phead == NULL || (*phead)->next == NULL)
	{
	printf("\nEither Empty List or List contains EXACTLY one node....\n");
	return;
	}
	loc = *phead;
	locp = NULL;
	
	while(loc != NULL)
	{
	locn = loc->next;
	loc->next = locp;
	locp = loc;
	loc = locn;
	}
	
	*phead = locp;
	return;
}
 
//Function definition to delete a particular element from the linked list
void del_node(struct list **phead, int item)
{
	struct list *loc, *locp;
	if(*phead == NULL)
	{
		printf("\nEmpty List ....So deletion is impossible....\n");
		return;
	}

	loc=*phead;
	while(loc != NULL && loc->info != item)
	{
		locp = loc;
		loc = loc->next;
	}

	if(loc == NULL)
	{
		printf("\nNode to be deleted is not found...\n");
		return;
	}

	if(loc == *phead)
		*phead = loc->next;
	else
		locp->next = loc->next;

	loc->next = NULL;
	free(loc);
	return;
}
 
//Function definition to insert an element before a particular element
void insert_before(struct list **phead, int item1, int item2)
{
	struct list *new_node = NULL;
    struct list *tmp = *phead;
    new_node = (struct list *)malloc(sizeof(struct list));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
        return;
    }

    new_node->info = item2;
    if ((*phead)->info == item1)
    {
        new_node->next = *phead;
        *phead = new_node;
        return;
    }

    while (tmp && tmp->next)
    {
        if (tmp->next->info == item1)
        {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return;
        }
        tmp = tmp->next;
    }
    /*Before node not found*/
    free(new_node);
}
 
//Function definition to insert element after a particular element
void insert_after(struct list *head, int item1, int item2)
{
	struct list *new_node = NULL;
	struct list *tmp = head;
	
	while(tmp)
	{
		if(tmp->info == item1)
		{
			// found the node
			new_node = (struct list *)malloc(sizeof(struct list));
			
			if (new_node == NULL)
			{
				printf("Failed to insert element. Out of memory");
			}
			
			new_node->info = item2;
			new_node->next = tmp->next;
			tmp->next = new_node;
			return;
		}
		tmp = tmp->next;
	}
}

/*
I/O :-
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 1

Enter the number of nodes: 5
Enter the information to be stored in a node: 1
Enter the information to be stored in a node: 2
Enter the information to be stored in a node: 3
Enter the information to be stored in a node: 4
Enter the information to be stored in a node: 5
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
1 2 3 4 5
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 3

Enter the information for the node to be inserted: 0
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
0 1 2 3 4 5
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 4

Enter the information for the node to be inserted: 6
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
0 1 2 3 4 5 6
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 5

Information on deleted note is 0
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 6

Information on deleted node is 6
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 7

Number of nodes: 5
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 8
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
5 4 3 2 1
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 9

Enter the element of node to delete: 1
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
5 4 3 2

1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 10

Enter the element of node before which you want to insert: 5

Enter the value to insert: 6
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
6 5 4 3 2
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 11

Enter the element of node after which you want to insert: 2

Enter the value to insert: 1
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 2
6 5 4 3 2 1
1.Create
2.Traverse
3.Insert First
4.Insert Last
5.Delete First
6.Delete Last
7.Count
8.Reverse
9.Delete a node with specific element
10.Insert a element before certain element
11.Insert a element after certain element
0.Exit
Your Choice: 0

Complexities:
TIME:
Indexing:	O(n)
Insert/delete at beginning:	O(1)
Insert/delete at end:	O(1) when last element is known;
						O(n) when last element is unknown
Insert/delete in middle:search time + O(1)
Wasted space (average):	O(n)
SPACE:
O(n) - Worst
*/

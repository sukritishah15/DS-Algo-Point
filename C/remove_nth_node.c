#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

//returns a node with the entered user data
struct node* createNode(int value)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

//appends a node with the given data, at the end of the linked list
void addNode(int val)
{
    struct node *ptr = createNode(val);
    if(head==NULL)
    {
        head = ptr;
        head->next = NULL;
    }
    //continue until we reach the end of the list
    else
    {
        struct node *k = head;
        while(k->next!=NULL)
        {
            k = k->next;
        }
        k->next = ptr;
    }
}

//delete node at nth position
void deleteNodeAt(int pos)
{
    struct node* ptr1 = head;
    if(head==NULL)
        {
            printf("The List is empty \n");
            return;
        }
        if(pos==1)
        {
            head = ptr1->next;
            free(ptr1);
        }
        else
        {
            //returns if the size of list is one and position entered is greater than given size
            if(ptr1->next==NULL)
            {
                printf("The list size is smaller than the position entered! \n");
                return;
            }
            int i;
            //moves the pointer to the (n-1)th node of nth node to be removed
            for(i=0; i<pos-2; i++)
            {
                ptr1 = ptr1->next;
                //returns if the position entered is greater than number of nodes in the list
                if(ptr1->next==NULL || ptr1==NULL)
                {
                    printf("The list size is smaller than the position entered! \n");
                    return;
                }
            }
            //points to the nth node to be removed
            struct node* ptr2 = ptr1->next;
            ptr1->next = ptr2->next;
            free(ptr2);
        }
}

void printList()
{
    if(head==NULL)
        printf("The list is empty\n");
    else
    {
        printf("List: ");
        struct node* p = head;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, num, p;
    while(1)
    {
        printf(" 1.  Append node at the end of list\n");
        printf(" 2.  Display the Linked list\n");
        printf(" 3.  Delete nth Node\n");
        printf(" 4.  Exit\n");
        printf("Enter the operation you want to perform: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the data of node: ");
            scanf("%d",&num);
            printf("\n");
            addNode(num);
            break;
        case 2:
            printList();
            break;
        case 3:
            p;
            printf("\nEnter the node position to be deleted: ");
            scanf("%d",&p);
            deleteNodeAt(p);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!!\n");
        }
    }
    return 0;
}

/*
        Program to remove nth node of a linked list.

Sample I/O

 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 1
Enter the data of node: 10

 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 1
Enter the data of node: 20

 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 1
Enter the data of node: 30

 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 2
List: 10 20 30
 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 3

Enter the node position to be deleted: 2
 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 2
List: 10 30
 1.  Append node at the end of list
 2.  Display the Linked list
 3.  Delete nth Node
 4.  Exit
Enter the operation you want to perform: 4

    Time Complexity : O(n)

*/

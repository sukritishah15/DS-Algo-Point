#include <stdio.h>
#include <stdlib.h>

typedef struct circularDLL{
    int data;
    struct circularDLL *prev;
    struct circularDLL *next;
} node;

// Creates and crturns the head of a new CLL
// Time Complexity: O(1)
node *createCLL(int ele)
{
    node *head = (node *)malloc(sizeof(node));

    head->data = ele;
    head->next = head;
    head->prev = head;

    printf("Element inserted\n");
    return head;
}

// Inserts a new element at the head of the circularSLL i.e. changes the head
// Time complexity: O(1)
void changeHead(node **head, int ele)
{
    node *temp;
    node *ptr = (node *)malloc(sizeof(node));

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    ptr->data = ele;

    temp = (*head)->prev;
    ptr->next = *head;
    ptr->prev = temp;

    (*head)->prev = ptr;

    *head = ptr;
    temp->next = *head;

    printf("Element inserted\n");
}

// Inserts an element at the end of the CLL
// Time Complexity: O(1)
void insertEnd(node **head, int ele)
{
    node *ptr,*last;
    ptr = (node *)malloc(sizeof(node));

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    ptr->data = ele;

    last = (*head)->prev;

    ptr->next = *head;
    ptr->prev = last;

    last->next = ptr;
    (*head)->prev = ptr;

    printf("Element inserted\n");
}

// Inserts a new element before a given element
// Time Complexity: O(N)
void insertBefore(node **head, int ele, int ref)
{
    int flag;
    node *ptr,*temp;
    ptr = (node *)malloc(sizeof(node));

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    temp = *head;
    flag = 0;

    while(temp->next != *head)
    {
        if(temp->next->data == ref)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(temp->next->data!=ref && flag == 0)
    {
        printf("Element not found\n");
        return;
    }

    ptr->data = ele;

    ptr->next = temp->next;
    ptr->prev = temp;

    temp->next->prev = ptr;
    temp->next = ptr;

    printf("Element inserted\n");
}

// Inserts a new element after a given element
// Time Complexity: O(N)
void insertAfter(node **head, int ele, int ref)
{
    int flag;
    node *ptr,*temp;
    ptr = (node *)malloc(sizeof(node));

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    temp = *head;
    flag = 0;

    while(temp->next != *head)
    {
        if(temp->data == ref)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 0 && temp->data != ref)
    {
        printf("Element not found\n");
        return;
    }

    ptr->data = ele;

    ptr->next = temp->next;
    ptr->prev = temp;

    temp->next->prev = ptr;
    temp->next = ptr;

    printf("Element inserted\n");
}

// Deletes the head of the CLL and assigns the next element as head
// Time Complexity: O(1)
void deleteHead(node **head)
{
    node *lastElement,*nextElement,*temp;

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    nextElement = (*head)->next;
    lastElement = (*head)->prev;
    temp = *head;

    nextElement->prev = lastElement;
    lastElement->next = nextElement;
    *head = nextElement;

    free(temp);

    printf("Element Deleted\n");
}

// Deletes the last element of the CLL and assigns the next element as head
// Time Complexity: O(1)
void deleteEnd(node **head)
{
    node *lastElement;

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    lastElement = (*head)->prev;

    (*head)->prev = lastElement->prev;
    lastElement->prev->next = *head;

    free(lastElement);

    printf("Element Deleted\n");
}

// Deletes a given element from the CLL
// Time Complexity: O(N)
void deleteElement(node **head,int ele)
{
    node *temp, *toBeDeleted;
    int flag = 0;

    if(*head == NULL)
    {
        printf("CLL does not exist. Create head first\n");
        return;
    }

    if((*head)->data == ele)
    {
        deleteHead(head);
        return;
    }

    temp = *head;
    flag = 0;

    while(temp->next != *head)
    {
        if(temp->next->data == ele)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 0)
    {
        printf("Element not found\n");
        return;
    }

    toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;
    toBeDeleted->next->prev = temp;

    free(toBeDeleted);

    printf("Element deleted\n");
}

// Returns the 1st occurrence of the given element in the circularSLL
// Time Complexity: O(N)
int searchElement(node *head, int ele)
{
    node *temp;
    int i,flag;

    if(head == NULL)
    {
        printf("CLL does not Exist.\n");
        return -2;
    }

    temp = head;
    i =0;
    flag = 0;

    while(temp->next != head)
    {
        if(temp->data == ele)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
        i++;
    }

    if(flag == 0 && temp->data != ele)
    {
        return -1;
    }

    if(temp->data == ele)
        i++;

    return i;
}

// Prints all the elements in the CLL
// Time Complexity: O(N)
void printCLL(node *head)
{
    node *temp;

    temp=head;

    while(temp->next !=head)
    {
        printf("%d < - > ",temp->data);
        temp = temp->next;
    }

    printf("%d < - > head\n",temp->data);

}

int main(int argc, char const *argv[])
{
    int ch=0,ele,ref,loc;
    char str;
    node *head = NULL;

    do
    {
        system("clear");

        printf("****** Circular Doubly Linked List ******\n\n");
        printf("1.Create CLL\n2.Change head\n3.Insert at end\n");
        printf("4.Insert before given Element\n5.Insert after given element\n");
        printf("6.Delete Head\n7.Delete last element\n8.Delete given element\n");
        printf("9.Search for given element\n10.Print CLL\n");
        printf("11.Exit\n\n");
        printf("Your choice -> ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1: system("clear");

                    printf("Enter element to be inserted -> ");
                    scanf("%d",&ele);

                    head = createCLL(ele);

                    break;

            case 2: system("clear");

                    printf("Enter element to be inserted -> ");
                    scanf("%d",&ele);

                    changeHead(&head,ele);
                    break;

            case 3: system("clear");

                    printf("Enter element to be inserted -> ");
                    scanf("%d",&ele);

                    insertEnd(&head,ele);
                    break;

            case 4: system("clear");

                    printf("Enter element to be inserted -> ");
                    scanf("%d",&ele);

                    printf("Insert Reference Element -> ");
                    scanf("%d",&ref);

                    insertBefore(&head,ele,ref);
                    break;

            case 5: system("clear");

                    printf("Enter element to be inserted -> ");
                    scanf("%d",&ele);

                    printf("Insert Reference Element -> ");
                    scanf("%d",&ele);

                    insertAfter(&head,ele,ref);
                    break;

            case 6: system("clear");
                    deleteHead(&head);
                    break;

            case 7: system("clear");
                    deleteEnd(&head);
                    break;

            case 8: system("clear");

                    printf("Enter Element to be deleted -> ");
                    scanf("%d",&ele);

                    deleteElement(&head,ele);
                    break;

            case 9: system("clear");

                    printf("Enter Element to be searched -> ");
                    scanf("%d",&ele);

                    loc  = searchElement(head,ele);

                    if(loc == -1)
                        printf("Element not found\n");
                    else if(loc > 0)
                        printf("Element found at position %d\n",loc);

                    printf("Search Complete\n");
                    break;

            case 10: system("clear");
                     printCLL(head);
                     break;

            case 11: break;

            default: system("clear");
                     printf("Invalid Input\n");
                     break;
        }

        printf("\nPress any key to continue...\n");
        getchar();
        getchar();

    } while(ch != 11);

    return(0);
}

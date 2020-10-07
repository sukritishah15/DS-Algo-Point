#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head=NULL;

node* createNode(int x)
{
    node *p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    return p;
}

void addNodeAtEnd()
{
    int x;
    cout<<"Enter the element:";
    cin>>x;
    node *p=createNode(x);
    if(head==NULL)
    {
        head=p;
        p->next=head;
    }
    else
    {
        node *ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        ptr->next=p;
        p->next=head;
    }
}

void traverse()
{
    node *p=head;
    if(head==NULL)
        cout<<"List is Empty!";
    else
    {
        cout<<p->data<<" ";
        p=p->next;
        while(p!=head)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
}

void deleteEndNode()
{
    if(head==NULL)
        cout<<"List is already empty!";
    else if(head->next==head)
    {
        cout<<"Value removed:"<<head->data;
        head=NULL;
    }
    else
    {
        node *ptr=head;
        while(ptr->next->next!=head)
            ptr=ptr->next;
        cout<<"Value removed:"<<ptr->next->data;
        ptr->next=head;
    }
}

void addNodeAtBeg()
{
    int x;
    cout<<"Enter an element:";
    cin>>x;
    node *p=createNode(x);
    if(head==NULL)
    {
        head=p;
        p->next=head;
    }
    else
    {
        node *ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        ptr->next=p;
        p->next=head;
        head=p;
    }
}

void deleteFirstNode()
{
    if(head==NULL)
        cout<<"The list is already empty!";
    else if(head->next==head)
    {
        cout<<"Element deleted is:"<<head->data;
        head=NULL;
    }
    else
    {
        node *p=head;
        while(p->next!=head)
            p=p->next;
        p->next=head->next;
        cout<<"Element deleted is:"<<head->data;
        head=head->next;
    }
}

int main()
{
    int choice;
    while(1)
    {
        system("cls");
        cout<<"1. Display List\n";
        cout<<"2. Add an element at end\n";
        cout<<"3. Add element at beginning\n";
        cout<<"4. Delete last element\n";
        cout<<"5. Delete First Element\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            addNodeAtEnd();
            cout<<"Value Inserted!!";
            break;
        case 3:
            addNodeAtBeg();
            cout<<"Value Inserted!!";
            break;
        case 4:
            deleteEndNode();
            break;
        case 5:
            deleteFirstNode();
            break;
        case 6:
            exit(0);
        default:
            cout<<"\nChoose valid option!!";
        }
        getch();
    }
}

/*
Sample I/O:

1. Display List
2. Add an element at end
3. Add element at beginning
4. Delete last element
5. Delete First Element
6. Exit
Enter your choice:2
Enter the element:3
Value Inserted!!

1. Display List
2. Add an element at end
3. Add element at beginning
4. Delete last element
5. Delete First Element
6. Exit
Enter your choice:3
Enter an element:2
Value Inserted!!

1. Display List
2. Add an element at end
3. Add element at beginning
4. Delete last element
5. Delete First Element
6. Exit
Enter your choice:1
2 3

1. Display List
2. Add an element at end
3. Add element at beginning
4. Delete last element
5. Delete First Element
6. Exit
Enter your choice:5
Element deleted is:2

1. Display List
2. Add an element at end
3. Add element at beginning
4. Delete last element
5. Delete First Element
6. Exit
Enter your choice:4
Value removed:3

1. Display List
2. Add an element at end
3. Add element at beginning
4. Delete last element
5. Delete First Element
6. Exit
Enter your choice:1
List is Empty!

Time complexity:O(n)
Space complexiy:O(1)

*/

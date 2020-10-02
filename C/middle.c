
/*The C program to find middle element of linked list
  
  The Time Complexity of this program is O(n)
  
  The Space Complexity of this program is O(1)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct node* next;
}Node;


Node* head=NULL;


void append(int data) 
{ 
    Node* new=(Node*) malloc(sizeof(Node)); 
    new->data=data; 
    if (head==NULL){
       head=new; 
       return; 
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new; 
    return; 
} 



void print(){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

void middle()  {  
    Node *slow=head;  
    Node *fast=head;  
    while (fast!=NULL && fast->next!=NULL){  
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
        
    }
    printf("%d\n", slow->data);
    
}


int main(int argc, char const *argv[])
{
    /* code */

    append(10);
    append(20);
    append(30);
    append(40);
    append(50);
    append(60);
    print();
    middle();
    return 0;
}

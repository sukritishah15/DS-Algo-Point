#include<iostream>
#include<stdlib.h>
using namespace std;

int arr[10], Front = -1, rear = -1, max_size = 10;

//returns true if both front and rear = -1
bool isEmpty()
{
    if(Front ==-1 && rear==-1)
        return true;
    else
        return false;
}

//returns true if position next to rear is front
bool isFull()
{
    if ((rear+1)% max_size == Front)
        return true;
    else
        return false;
}

//push an element in the queue
void enqueuqe(int val)
{
    if(isFull())
     {
        cout<<"The queue is full!\n";
        return;
     }
    else if(isEmpty())
        rear = Front = 0;
    else
        rear = (rear+1)% max_size;

    arr[rear] = val;
}

//pops out the first element from the given queue
void dequeue()
{
    if (isEmpty())
    {
        cout<<"The queue is Empty!\n";
        return;
    }
    else if(Front==rear)
        Front = rear = -1;
    else
        Front = (Front+1)% max_size;
}

void display()
{
    if(isEmpty())
    {
        cout<<"The queue is Empty!\n";
        return;
    }
    else
        cout<<"The element at front of the queue is : "<<arr[Front]<<"\n";
}
int main()
{
    int choice, num;
    while(1)
    {
        cout<<" 1.  Insert an element in the queue\n";
        cout<<" 2.  Pop the first element out of the queue\n";
        cout<<" 3.  Display the element at front of the queue\n";
        cout<<" 4.  Exit\n";
        cout<<"Enter the operation you want to perform: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be entered: ";
            cin>>num;
            cout<<"\n";
            enqueuqe(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"Invalid choice!!\n";
        }
    }
    return 0;
}
/*

        Array implementation of queue

Sample I/O

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 1
Enter the element to be entered: 10

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 1
Enter the element to be entered: 20

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 3
The element at front of the queue is : 10

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 2

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 3
The element at front of the queue is : 20

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 2

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 3
The queue is Empty!

 1.  Insert an element in the queue
 2.  Pop the first element out of the queue
 3.  Display the element at front of the queue
 4.  Exit
Enter the operation you want to perform: 4

    Time Complexity : O(1)

*/

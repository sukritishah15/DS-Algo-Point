//Implementation of Circular Queue in C++
#include <iostream>
using namespace std;

//Defined class CircularQueue 
class CircularQueue{
    private:
        int *  circular_queue;
        int front, rear, queue_size;
    public:
        // Parameterized constructor
        CircularQueue(int Qsize){
            front = rear = -1;
            circular_queue = new int[Qsize];
            queue_size = Qsize;
        }
        
        //Function to check whether the circular queue is full or not
        bool isFull(){
            if((front==0 && rear==queue_size-1) || (front == rear+1)){
                return true;
            }else{
                return false;
            }
        }
        
        //Function to check whether the circular queue is empty or not
        bool isEmpty(){
            if(front == -1){
                return true;
            }else{
                return false;
            }
        }
        
        //Function to insert an element in the circular queue
        void Enqueue(int val){
            if(isFull()){
                cout<<"Overflow:The Circular queue is full, can't add any more elements!"<<"\n";
            }else{
                if(isEmpty()){
                    front = rear = 0;
                }else{
                    if(rear == queue_size-1){
                        rear = 0;
                    }else{
                        rear++;
                    }
                } 
                circular_queue[rear] = val;
                Display();
            } 
        }
        
        //Function to delete an element from the circular queue
        void Dequeue(){
            if(isEmpty()){
                cout<<"Underflow:The Circular queue is empty, can't remove any more elements!"<<"\n";
                
            }else{
                if(front==rear){
                    front = rear = -1;
                }else{
                    if(front == queue_size-1){
                        front = 0;
                    }else{
                        front++;
                    }
                }
                Display();
            }
        }
        
        //Function to display the circular queue
        void Display(){
            //Remove below comment to view working of trackers
            //cout<<"Front:"<<front<<" "<<"Rear:"<<rear<<"\n";
            if(isEmpty()){
                cout<<"Queue is empty.";
            }else{
                if(rear>=front){
                    for(int i=front;i<=rear;i++){
                        cout<<circular_queue[i]<<"<--";
                    }
                }else{
                    for(int i=front;i<queue_size;i++){
                    cout<<circular_queue[i]<<"<--";
                    }
                    for(int i=0;i<=rear;i++){
                        cout<<circular_queue[i]<<"<--";
                    }
                }
                
            }
            cout<<"\n";
        } 
};

int main() {
    
    int Qsize;
    cout<<"Enter the size of your desired circular queue:"<<"\n";
    cin>>Qsize;
    
    //Create an instance of Circular Queue
    CircularQueue myFirstCQueue(Qsize);
    int choice=1;
    do{ 
        cout<<"Circular Queue functionalities:"<<"\n";
        cout<<"1.Enqueue"<<"\n";
        cout<<"2.Dequeue"<<"\n";
        cout<<"3.Display"<<"\n";
        cout<<"4.Is Empty"<<"\n";
        cout<<"5.Is Full"<<"\n";
        cout<<"6.Exit"<<"\n\n";
        cout<<"Please enter your choice:"<<"\n";
        cin>>choice;
        int temp;
        switch(choice){
            case 1:
                    cout<<"Enter value to be entered:"<<"\n";
                    cin >> temp;
                    myFirstCQueue.Enqueue(temp);
                    break;
            case 2:
                    myFirstCQueue.Dequeue();
                    break;
            case 3:
                    myFirstCQueue.Display();
                    break;
            case 4:
                    if(myFirstCQueue.isEmpty()){
                        cout<<"Circular Queue is empty!";
                    }else{
                        cout<<"Circular Queue is not empty!";
                    }
                    break;
            case 5:
                    if(myFirstCQueue.isEmpty()){
                        cout<<"Circular Queue is full!";
                    }else{
                        cout<<"Circular Queue is not full!";
                    }
                    myFirstCQueue.isFull();
                    break;
            default:
                    break;
        }
    }while(choice!=6);
    return 0;
}

/*
Circular Queue is a Data Structure similar to a linear Queue.It follows the FIFO (First in First Out)
principle.In a linear queue there arises a condition where if the queue is full, even after
deque operations more elements cannot be added to it.Circular queue overcomes these limitations of linear 
queue as it connects the rear end of the queue to the front end.Because of this it is also called a 
'Ring Buffer'.

Sample I/O : 
Enter the size of your desired circular queue:5
Circular Queue functionalities:
1.Enqueue
2.Dequeue
3.Display
4.Is Empty
5.Is Full
6.Exit

Please enter your choice:1
Enter value to be entered:10
10<--
Circular Queue functionalities:
1.Enqueue
2.Dequeue
3.Display
4.Is Empty
5.Is Full
6.Exit

Please enter your choice:1
Enter value to be entered:20
10<--20<--
Circular Queue functionalities:
1.Enqueue
2.Dequeue
3.Display
4.Is Empty
5.Is Full
6.Exit

Please enter your choice:1
Enter value to be entered:30
10<--20<--30<--
Circular Queue functionalities:
1.Enqueue
2.Dequeue
3.Display
4.Is Empty
5.Is Full
6.Exit

Please enter your choice:2
20<--30<--
Circular Queue functionalities:
1.Enqueue
2.Dequeue
3.Display
4.Is Empty
5.Is Full
6.Exit

Please enter your choice:1
Enter value to be entered:80
20<--30<--80<--
Circular Queue functionalities:
1.Enqueue
2.Dequeue
3.Display
4.Is Empty
5.Is Full
6.Exit

Please enter your choice:6
*/

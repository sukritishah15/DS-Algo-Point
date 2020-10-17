package Java.DataStructures;

import java.util.*;


public class CircularQueue {
    public static void main ( String[] args)
    {
         Scanner sc=new Scanner(System.in);
         System.out.println("Enter the size of circular queue: ");
         int n=sc.nextInt();
         Queue q=new Queue(n);
         while(true)
         {
        System.out.println("Press 1:To insert\n Press 2:To delete \n Press 3:To display \n Press 4:To Exit");
       int option=sc.nextInt();
       
      switch(option)
        {
            case 1: {System.out.println("Enter the element");
                          final int num=sc.nextInt();
                          q.insert(num);  }
                          break;
            case 2: {q.delete();}     
                          break;
            case 3:{q.display();}
                          break;
            case 4: System.exit(0);        //terminating the program                   

        }
        }

       }

    }

class Queue
{ 

   int front= -1;
   int rear= -1;
   int size;
   int [] cqueue;
   public Queue(final int size)
   {this.size=size;
     cqueue=new int[size];
   }

   // Inesrtion of element from rear in queue
  public void insert(final int data)
  {
   if((rear+1)%size==front)
       {
           System.out.println("Queue is full");
           return;

       }
    else if(rear==-1 && front==-1)
    {  rear=0;
       front=0; }
     else if(rear==(size-1) && front!=0)
     {rear=0;}

    else
    {rear=(rear+1)%size;

    }
    cqueue[rear] = data;
  }
//    deletion of element from front in queue
  public void delete()
  {
           int val;

          if(front==-1 && rear==-1)
          {
              System.out.println("Queue is empty");
              return ;
          }
          else if(front==rear)
          {  val=cqueue[front];
              front=-1;
              rear=-1;
          }
          else if(front==size-1)
          {   val=cqueue[front];
              front=0; }
          else
          {
              val=cqueue[front];
              front++;
          }
         System.out.println("deleted element is :"+val);


  }
// printing the queue
  public void display()
  {   if(front==-1)
       {
           System.out.println("Queue is Empty");
       }
       else if(front <=rear)
       {for(int i=front;i<=rear;i++)
           {
               System.out.print(cqueue[i]+" ");
           }

       }
       else if(front>rear)
       {for(int i=front;i<=size-1;i++)
           {
               System.out.print(cqueue[i]+" ");
           }
         for(int i=0;i<=rear;i++)
         {
             System.out.print(cqueue[i]+" ");
         }

        }



 }

}

/* Operations on Circular Queue
Sample I/O
Input
Size of circular queue:
Select the command: press 1 to insert element
                    press 2 to delete element
                    press 3 to diplay the queue
                    press 4 to exit from code

Output
display of queue

Example 1:Suppose the size of the queue is 3
           insert(3);
           insert(4);
           insert(7);
  if you again hit insert command like
           insert(5);

  Output is =>Queue is full

  if you hit display command the only starting 3 element in queue is shown
  Output is=>3 4 7

  if you hit delete command then the last element to inserted , will get delete
  Output is=>3 4

  to exit from the code hit 4 to exit.



Time Complexity:O(1)
Space Complexity:O(1)

*/

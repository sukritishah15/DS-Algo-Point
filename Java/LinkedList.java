public class LinkedList { 
  
    Node head; 
    static class Node { 
  
        int data; 
        Node next; 
  
        // Constructor 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    }  
    public static LinkedList insert(LinkedList list, int data) 
    { 
        Node new_node = new Node(data); 
        new_node.next = null; 
  
        if (list.head == null) { 
            list.head = new_node; 
        } 
        else { 
            Node last = list.head; 
            while (last.next != null) { 
                last = last.next; 
            } 
            last.next = new_node; 
        } 

        return list; 
    } 
    public static void printList(LinkedList list) 
    { 
        Node n = list.head; 
   
        System.out.print("The Linked List is "); 
        
        while (n != null) { 
            System.out.print(n.data + " "); 
            n=n.next; 
        } 
    } 
    public static void deleteN(LinkedList l,int p) 
    { 
        if (l.head == null) 
            return; 
        Node n = l.head; 
        if (p == 0) 
        { 
            l.head = n.next; 
            return; 
        } 
        for (int i=0; n!=null && i<p-1; i++) 
            n = n.next; 
 
        
        Node n1 = n.next.next; 
  
        n.next = n1;
    } 
    public static void main(String[] args) 
    { 
        LinkedList list = new LinkedList();   
        list = insert(list, 1); 
        list = insert(list, 2); 
        list = insert(list, 3); 
        list = insert(list, 4); 
        list = insert(list, 5); 
        list = insert(list, 6); 
        list = insert(list, 7); 
        list = insert(list, 8);

        printList(list); 

        deleteN(list,4);
        
        printList(list);

    /*
    Output: The Linked List is  1 2 3 4 5 6 7 8
            The Linked List is  1 2 3 4 6 7 8
            
    Space Complexity: O(n)
    Time Complexity: O(n)
    */
    

    } 
} 

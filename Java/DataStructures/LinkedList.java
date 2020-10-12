<<<<<<< HEAD:Java/LinkedList.java
public class LinkedList {

    private Node head;
    private int size;

    /* Add Methods */
    public boolean add(int value) {
        if (head == null) {
            head = new Node(value);
            size++;
            return true;
        }

        Node toAdd = new Node(value);
        Node current = head;

        while (current.next != null) {
            current = current.next;
        }

        current.next = toAdd;
        size++;
        return true;
    }

    public boolean addAtLocation(int value, int location) {
        Node toAdd = new Node(value);

        if (location == 0) {
            toAdd.next = head;
            head = toAdd;
            size++;
            return true;
        }

        Node current = head;

        if (location > size) {
            while (current.next != null) {
                current = current.next;
            }

            current.next = toAdd;
            size++;
            return true;
        }

        for (int i = 0; i < location-1; i++) {
            current = current.next;
        }

        toAdd.next = current.next;
        current.next = toAdd;
        size++;
        return true;
    }

    /* Remove Methods */

    public boolean remove(int value) {
        if (head == null) {
            return false;
        }
        if (head.data == value) {
            head = head.next;
            size--;
            return true;
        }
        Node current = head;
        while (current.next != null) {
            if (current.next.data == value) {
                size--;
                current.next = current.next.next;
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public boolean removeAtLocation(int value, int location) {
        if (head == null) {
            return false;
        }
        if (location > size) {
            return false;
        }
        if (location == 0 && head.data == value) {
            head = head.next;
            size--;
            return true;
        }

        Node current = head;

        for (int i = 0; i < location-1; i++) {
            current = current.next;
        }

        if (current.next.data == value) {
            current.next = current.next.next;
            size--;
            return true;
        }

        return false;

    }

    public boolean clear() {
        head = null;
        size = 0;
        return true;
    }

    /* indexOf Methods */

    public int indexOf(int value) {
        int index = 0;
        if (head == null) {
            return -1;
        }
        Node current = head;
        while (current != null) {
            if (current.data == value) {
                return index;
            }
            current = current.next;
            index++;
        }
        return -1;
    }

    public int indexOfFirstAppearance(int value) {
        return indexOf(value);
    }

    public int indexOfLastAppearance(int value) {
        int index = 0;
        int position = -1;
        if (head == null) {
            return -1;
        }
        Node current = head;
        while (current != null) {
            if (current.data == value) {
                position = index;
            }
            current = current.next;
            index++;
        }
        return position;
    }


    /* Other Methods */

    public boolean contains(int value) {
        if (head == null) {
            return false;
        }
        Node current = head;
        while (current != null) {
            if (current.data == value) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public int size() {
        return size;
    }

    @Override
    public String toString() {
        String output = "";
        if (head == null) {
            return output;
        }
        Node current = head;
        while (current != null) {
            output += current.data + " ";
            current = current.next;
        }
        return output;
    }

    /* Main Methods */
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.add(3); // 3
        list.add(3); // 3 3
        list.add(7); // 3 3 7
        list.addAtLocation(1, 2); // 3 3 1 7
        list.addAtLocation(4, 9); // 3 3 1 7 4

        list.indexOf(3); // 0
        list.indexOfFirstAppearance(3); // 0
        list.indexOfLastAppearance(3); // 1

        list.contains(3); // true
        list.contains(8); // false

        list.size(); // 5

        list.remove(3); // 3 1 7 4
        list.remove(6); // 3 1 7 4
        list.removeAtLocation(7, 2); // 3 1 4
        list.removeAtLocation(1, 9); // 3 1 4

        list.clear(); // true
    }


    /* Node Class*/
    private class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
        }
    }
=======
package Java.DataStructures;

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
>>>>>>> 465b4ffe1903f4e65b0e1576096e08cab0a50ec3:Java/DataStructures/LinkedList.java

    /*
    Space Complexity: O(n)
    Time Complexity: O(n)
     */
}

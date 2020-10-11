package Java.DataStructures;

class SListNode {
    int item;
    SListNode next;

    SListNode(int obj, SListNode next) {
        item = obj;
        this.next = next;
    }

    SListNode(int obj) {
        this(obj, null);
    }
}

public class CircularSList{

    private SListNode head;
    private long size;

    public CircularSList(){
        size = 0;
        head = new SListNode(Integer.MIN_VALUE);
        head.next = head;
        size = 0;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public long length(){
        return size;
    }

    public Object head(){
        if(size == 0){
            return null;
        }
        return head.next.item;
    }

    public Object tail(){
        if(size == 0){
            return null;
        }
        SListNode node = head.next;
        while(node.next != head){
            node = node.next;
        }
        return node.item;
    }

    public void insertFront(int obj){
        SListNode node = new SListNode(obj, head.next);
        head.next = node;
        size++;
    }

    public void insertEnd(int obj){
        SListNode node = new SListNode(obj);
        SListNode node2 = head.next;
        while(node2.next != head){
            node2 = node2.next;
        }
        node2.next = node;
        node.next = head;
        size++;
    }

    public void removeFront(){
        if(size == 0){
            return;
        }
        head.next = head.next.next;
        size--;
    }

    public void removeEnd(){
        if(size == 0){
            return;
        }
        SListNode current, prev;
        current = head.next;
        prev = current;
        while(current.next != head){
            prev = current;
            current = current.next;
        }
        prev.next = head;
        size--;
    }

    public String toString(){
        String result = "[ ";
        SListNode current = head.next;
        while(current != head){
            result = result + current.item + " ";
            current = current.next;
        }
        return result + "]";
    }


    public static void main(String[] args) {

        CircularSList lst1 = new CircularSList();
        System.out.println("Here is a list after construction: "
                + lst1.toString());
        System.out.println("isEmpty() should be true. It is: " +
                lst1.isEmpty());
        System.out.println("length() should be 0. It is: " +
                lst1.length());
        lst1.insertFront(3);
        System.out.println("Here is a list after insertFront(3) to an empty list: "
                + lst1.toString());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());


        lst1 = new CircularSList();
        lst1.insertFront(3);
        lst1.insertFront(2);
        lst1.insertFront(1);
        System.out.println();
        System.out.println("Here is a list after insertFront 3, 2, 1: "
                + lst1.toString());
        System.out.println("isEmpty() should be false. It is: " +
                lst1.isEmpty());
        System.out.println("length() should be 3. It is: " +
                lst1.length());
        lst1.insertEnd(4);
        System.out.println("Here is the same list after insertEnd(4): "
                + lst1.toString());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());


        lst1 = new CircularSList();
        lst1.insertEnd(6);
        lst1.insertEnd(7);
        System.out.println();
        System.out.println("Here is a list after insertEnd 6, 7: "
                + lst1.toString());
        System.out.println("isEmpty() should be false. It is: " +
                lst1.isEmpty());
        System.out.println("length() should be 2. It is: " +
                lst1.length());
        lst1.insertFront(5);
        System.out.println("Here is the same list after insertFront(5): "
                + lst1.toString());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());


        lst1 = new CircularSList(); lst1.insertEnd(1);
        lst1.insertEnd(2);
        lst1.insertEnd(3);
        lst1.insertEnd(4);
        lst1.insertEnd(5);
        lst1.insertEnd(6);
        System.out.println();
        System.out.println("Here is a list after insertEnd 1,2,3,4,5,6: "
                + lst1.toString());
        System.out.println("isEmpty() should be false. It is: " +
                lst1.isEmpty());
        System.out.println("length() should be 6. It is: " +
                lst1.length());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());
        lst1.insertFront(5);
        System.out.println("Here is the same list after insertFront(5): "
                + lst1.toString());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());
        lst1.removeFront();
        lst1.removeFront();
        System.out.println("Here is the same list after two removeFront(): "
                + lst1.toString());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());
        lst1.removeEnd();
        lst1.removeEnd();
        System.out.println("Here is the same list after two removeEnd(): "
                + lst1.toString());
        System.out.println("Head is: " + lst1.head() + "\nTail is: " + lst1.tail());




    }

}


/*
 * Implementation of Circular Singly Linked List in Java.
 *
 * Sample I/O:
 *
 * Input:-
 * CircularSList lst1 = new CircularSList();
 * lst1.insertFront(5);
 * lst1.insertFront(4);
 * lst1.insertFront(3);
 *
 * Output:-
 * lst1.toString() should output: [ 3 4 5 ]
 *
 * Time Complexity:
 * Insertion at front:- O(1).
 * Insertion at end:- O(n).
 * Deletion from front:-O(1).
 * Deletion from end:- O(n).
 *
 */



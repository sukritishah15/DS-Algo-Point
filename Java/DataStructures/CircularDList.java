package Java.DataStructures;

class DListNode {

    public int item;
    public DListNode prev;
    public DListNode next;

    DListNode() {
        item = 0;
        prev = null;
        next = null;
    }

    DListNode(int i) {
        item = i;
        prev = null;
        next = null;
    }

}


public class CircularDList {


    protected DListNode head;
    protected long size;

    public CircularDList() {
        head = new DListNode();
        head.item = Integer.MIN_VALUE;
        head.next = head;
        head.prev = head;
        size = 0;
    }

    public CircularDList(int a) {
        head = new DListNode();
        head.item = Integer.MIN_VALUE;
        head.next = new DListNode();
        head.next.item = a;
        head.prev = head.next;
        head.next.prev = head;
        head.prev.next = head;
        size = 1;
    }

    public CircularDList(int a, int b) {
        head = new DListNode();
        head.item = Integer.MIN_VALUE;
        head.next = new DListNode();
        head.next.item = a;
        head.prev = new DListNode();
        head.prev.item = b;
        head.next.prev = head;
        head.next.next = head.prev;
        head.prev.next = head;
        head.prev.prev = head.next;
        size = 2;
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
        return head.prev.item;
    }
    public void insertFront(int i) {
        DListNode node = new DListNode(i);
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
        size++;
    }

    public void insertEnd(int i){
        DListNode node = new DListNode(i);
        node.next = head;
        node.prev = head.prev;
        head.prev.next = node;
        head.prev = node;
        size++;
    }

    public void removeFront() {
        if(size == 0){
            return;
        }
        DListNode node = head.next;
        node.next.prev = head;
        head.next = node.next;
        size--;
    }

    public void removeEnd(){
        if(size == 0){
            return;
        }
        DListNode node = head.prev;
        node.prev.next = head;
        head.prev = node.prev;
        size--;
    }

    public String toString() {
        String result = "[  ";
        DListNode current = head.next;
        while (current != head) {
            result = result + current.item + "  ";
            current = current.next;
        }
        return result + "]";
    }

    public static void main(String[] args) {

        CircularDList lst1 = new CircularDList();
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


        lst1 = new CircularDList();
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


        lst1 = new CircularDList();
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


        lst1 = new CircularDList();
        lst1.insertEnd(1);
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
 * Implementation of Circular Doubly Linked List in Java.
 *
 * Sample I/O:
 *
 * Input:-
 * DList lst1 = new DList();
 * lst1.insertFront(5);
 * lst1.insertFront(4);
 * lst1.insertFront(3);
 *
 * Output:-
 * lst1.toString() should output: [ 3 4 5 ]
 *
 * Time Complexity:
 * Insertion at front:- O(1).
 * Insertion at end:- O(1).
 * Deletion from front:-O(1).
 * Deletion from end:- O(1).
 *
 */



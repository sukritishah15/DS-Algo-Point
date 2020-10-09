package Java.DataStructures;

class DListNode{

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


public class DList {

    protected DListNode head;
    protected DListNode tail;
    protected long size;

    public DList() {
        head = null;
        tail = null;
        size = 0;
    }

    public DList(int a) {
        head = new DListNode();
        tail = head;
        head.item = a;
        size = 1;
    }

    public DList(int a, int b) {
        head = new DListNode();
        head.item = a;
        tail = new DListNode();
        tail.item = b;
        head.next = tail;
        tail.prev = head;
        size = 2;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public long length(){
        return size;
    }
    public void insertFront(int i) {
        DListNode node = new DListNode(i);
        if(size == 0){
            head = tail = node;
        }else {
            node.next = head;
            head.prev = node;
            head = node;
        }
        size++;
    }

    public void insertEnd(int i){
        DListNode node = new DListNode(i);
        if(size == 0){
            head = tail = node;
        }else{
            node.prev = tail;
            tail.next = node;
            tail = node;
        }
        size++;
    }

    public void removeFront() {
        if(size > 1){
            head = head.next;
            head.prev = null;
            size--;
        }
        else{
            head = tail = null;
            size = 0;
        }
    }

    public void removeEnd(){
        if(size > 1){
            tail = tail.prev;
            tail.next = null;
            size--;
        }else{
            head = tail = null;
            size = 0;
        }
    }
    
    public Object head(){
        if(head==null){
            return null;
        }
        return head.item;
    }

    public Object tail(){
        if(tail == null){
            return null;
        }
        return tail.item;
    }

    public String toString() {
        String result = "[  ";
        DListNode current = head;
        while (current != null) {
            result = result + current.item + "  ";
            current = current.next;
        }
        return result + "]";
    }

    public static void main(String[] args) {


        DList lst1 = new DList();
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


        lst1 = new DList();
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


        lst1 = new DList();
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


        lst1 = new DList();
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
 * Implementation of Doubly Linked List in Java.
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


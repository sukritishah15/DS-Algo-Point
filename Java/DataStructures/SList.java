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


public class SList {

    private SListNode head;
    private SListNode tail;
    private int size;


    public SList() {
        size = 0;
        head = null;
        tail = null;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int length() {
        return size;
    }


    public void insertFront(int obj) {
        head = new SListNode(obj, head);
        if(size == 0){
            tail = head;
        }
        size++;
    }


    public void insertEnd(int obj) {
        SListNode node = new SListNode(obj);
        if (size == 0) {
            head = tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
        size++;
    }

    public void removeFront(){
        if(size == 0){
            return;
        }
        else{
            head = head.next;
            size--;
        }
        if(size == 0){
            head = tail = null;
        }
    }

    public void removeEnd(){
        if(head == null){
            return;
        }
        else{
            SListNode current;
            current = head;
            while(current.next != tail){
                current = current.next;
            }
            current.next = null;
            tail = current;
            size--;
            return;
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
        int i;
        Object obj;
        String result = "[  ";

        SListNode cur = head;

        while (cur != null) {
            obj = cur.item;
            result = result + obj.toString() + "  ";
            cur = cur.next;
        }
        result = result + "]";
        return result;
    }

    public static void main(String[] args){
        SList lst1 = new SList();
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


        lst1 = new SList();
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


        lst1 = new SList();
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


        lst1 = new SList();
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
 * Implementation of Singly Linked List in java.
 *
 * Sample I/O:
 * 
 * Input:-
 * SList lst1 = new SList();
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
 * Deletion from front:- O(1).
 * Deletion from end:- O(n).
 *
 */



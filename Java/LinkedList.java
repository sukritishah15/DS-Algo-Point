public class LinkedList {

    private Node head;
    private int size;

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


    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(3);
        list.add(2);
        list.add(7);
        list.addAtLocation(1, 2);
        list.addAtLocation(4, 9);
        System.out.println(list.toString());
        // 3 3 1 7 4
    }

    private class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    /*
    Space Complexity: O(n)
    Time Complexity: O(n)
     */
}

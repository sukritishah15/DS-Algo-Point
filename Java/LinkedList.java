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
        list.add(3);
        list.add(3);
        list.add(7);
        list.addAtLocation(1, 2);
        list.addAtLocation(4, 9);
        System.out.println(list.toString());
    }


    /* Node Class*/
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

package Java.Algorithms;

public class SwapNumbersWithoutThirdVariable {
    public static void main(String[] args) {
        int x = 9;
        int y = 4;

        x = x + y;
        y = x - y;
        x = x - y;

        System.out.println(x);
        System.out.println(y);

        //Time Complexity: O(1).
        //Space Complexity: O(1).

        /*
        Sample I/O:

        ORIGINAL VALUES
        x = 9, y = 4

        AFTER SWAP
        x = 4, y = 9

        PRINTS
        4
        9
         */
    }
}

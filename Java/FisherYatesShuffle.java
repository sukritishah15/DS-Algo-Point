import java.util.Random;

public class FisherYatesShuffle {
    // Shuffles the array passed in randomly by iterating through the array
    public static int[] shuffle(int[] array) {
        Random random = new Random();

        for (int i = 0; i < array.length; i++) {
            int place = random.nextInt(i+1);

            int current = array[i];

            int temporaryNumber = array[place];
            array[place] = array[i];
            array[i] = temporaryNumber;
        }
        return array;
    }
    // Main Function
    public static void main(String[] args) {
        int[] elements = {1, 2, 3, 4, 5};
        shuffle(elements);
        for (int e : elements) {
            System.out.print(e + " ");
        }
    }

    /*
    Sample I/O:

    Input: 1, 2, 3, 4, 5
    Output: 3, 4, 1, 5, 2

    Time Complexity: O(n)
    Space Complexity: O(n)
     */
}

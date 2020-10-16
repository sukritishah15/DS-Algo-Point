public class PythagoreanTriplets {
    /* Takes in an array and determines if the array contains a set of three Pythagorean triplets */
    public static boolean containsTriplet(int[] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = i+1; j < array.length ; j++) {
                for (int k = j+1; k < array.length; k++) {
                    if (array[i] * array[i] + array[j] * array[j] == array[k] * array[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /* Takes in three numbers and determines whether or not the three numbers are Pythagorean triplets */
    public static boolean isTriplet(int a, int b, int c) {
        if (a * a + b * b == c * c) {
            return true;
        }
        return false;
    }

    /* Main method that contains the tests */
    public static void main(String[] args) {
        int[] elements = {3, 1, 4, 6, 5};
        System.out.println(containsTriplet(elements));
        System.out.println(isTriplet(3, 4, 5));
    }

    /*
    Sample I/O
    Input: {3, 1, 4, 6, 5}
    Output: True

    Input: 3, 4, 5
    Output: True

    Complexity for containsTriplet() --> O(n)
    Complexity for isTriplet() --> O(1)
     */
}

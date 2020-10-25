import java.util.Arrays;

public class PrefixSumsArray {

    /* Returns an array of integers that calculates range sums */
    public static int[] prefixSums(int[] nums) {
        int[] arraySums = new int[nums.length];
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j <= i; j++) {
                count += nums[j];
            }
            arraySums[i] = count;
            count = 0;
        }
        return arraySums;
    }

    /* Main method */
    public static void main(String[] args) {
        int[] elements = {1, 2, 3, 4, 5};
        System.out.println(Arrays.toString(prefixSums(elements)));
    }

    /*
    Sample I/O:

    Input: [1, 2 ,3 ,4, 5]
    Output: [1, 3, 6, 10, 15]

    Time Complexity: O(n)
    Space Complexity: O(n)
     */
}

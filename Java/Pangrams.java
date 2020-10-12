public class Pangrams {
    public static boolean isPangram(String phrase) {
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        char[] letters = alphabet.toCharArray();

        for (char c : letters) {
            if (phrase.indexOf(c) < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        isPangram("The quick brown fox jumps over the lazy dog");
        isPangram("Hello");
    }
    /*
    Sample I/O:

    Input: The quick brown fox jumps over the lazy dog
    Output: true

    Input: Hello
    Output: false

    Time Complexity: O(n)
    Space Complexity: O(n)
     */
}

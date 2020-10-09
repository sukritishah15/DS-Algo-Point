public class Panagrams {
    public static boolean isPanagram(String phrase) {
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
        isPanagram("The quick brown fox jumps over the lazy dog");
        isPanagram("Hello");
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

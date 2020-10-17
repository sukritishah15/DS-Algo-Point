import java.util.Scanner

val scanner = Scanner(System.`in`)

/*
* Check if the given word or string is PANGRAM (If it contains every letter of the alphabet at least once).
*
* For example, "The quick brown fox jumps over the lazy dog" is a well-known pangram.
*
*/
fun main() {
    val aString: String = scanner.nextLine()

    println(aString.isPangram())
}

private const val ALPHABET = "abcdefghijklmnopqrstuvwxyz"

private fun String.isPangram() =
        ALPHABET.all { contains(it, ignoreCase = true) }

/*
* Input:
* - a first word.
*
* Output:
* Print "true" if the word is a pangram.
*
* Example 1:
*
* Input 1: The quick brown fox jumps over the lazy dog
* Output 1: true
*
* Input 2: marganaa
* Output 2: false
*
* Time Complexity : O(N).
* Space Complexity : O(N).
*/
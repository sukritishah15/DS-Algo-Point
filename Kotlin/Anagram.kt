/*
* Two words are called anagrams if they contain all the same characters in the same frequencies.
* For example, the anagrams of CAT are CAT, ACT, TAC, TCA, ATC, and CTA.
*/
fun main() {
    val aWord: String = scanner.next()
    val anotherWord: String = scanner.next()

    println(aWord isAnagramOf anotherWord)
}

/**
 * Transform both words into a Map<Char, List<Char>> and then compare them.
 */
private infix fun String.isAnagramOf(anotherWord: String): Boolean =
        this.groupBy { it } == anotherWord.groupBy { it }

/*
* Input:
* - a first word.
* - a second word.
*
* Output:
* Print "true" if both words are anagrams of each other; otherwise, print "false" instead.
*
* Example 1:
*
* Input 1:
* - anagram
* - margana
* Output 1: true
*
* Input 2:
* - anagramm
* - marganaa
* Output 2: false
*
* Time Complexity : O(N + M), N and M are the lengths of both words respectively.
* Space Complexity : O(N + M), N and M are the lengths of both words respectively.
*/

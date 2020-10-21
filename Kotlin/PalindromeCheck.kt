fun main() {
    val aWord: String = scanner.next()

    println(message = aWord.isPalindromeOf())

}

//* just compare reversed string and not reversed
private fun String.isPalindromeOf(): Boolean = this.reversed() == this


/*
* Input:
* - a word
*
* Output:
* Print "true" if  word are palindrome; otherwise, print "false" instead.
*
* Example 1:
*
* Input 1:
* - level
* Output 1: true
*
* Input 2:
* - hello
* Output 2: false
*
* Time Complexity : O(N), N the length of word.
* Space Complexity : O(2N), N the length of words.
*
 */
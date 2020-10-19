fun main() {
    val aWord: String = scanner.next()
    val anotherWord: String = scanner.next()

    println(message = aWord isPalindromeOf anotherWord)

}

//* just compare reversed string and not reversed
private infix fun String.isPalindromeOf(anotherWord: String): Boolean = this.reversed() == anotherWord.toString()

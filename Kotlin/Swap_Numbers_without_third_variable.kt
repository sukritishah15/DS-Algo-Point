import java.util.*

/***
Program: Swap two numbers without third variable.
Language: KOTLIN
Input: two variables
output: both variable swapped

 *Time Complexity - O(1)
 *Space Complexity - O(1)
 *
 * Sample Input
 *                 -4 8
 * Sample Output -
                a = -4 , b = 8
                Swapping a <--> b
                Swapping completed
                a = 8 , b = -4
 ***/

fun main() {
    val scanner = Scanner(System.`in`)  //initialized scanner object for reading input from stdin (console)
    var a: Int = scanner.nextInt()
    var b: Int = scanner.nextInt()

    println("a = $a , b = $b")

    if (a != b) {
        println("Swapping a <--> b")

        a = a.xor(b)    //if xor not allowed then you can do - a = a + b
        b = a.xor(b)    // b = a - b
        a = a.xor(b)    // a = a - b

        println("Swapping completed")
    }

    println("a = $a , b = $b")
}


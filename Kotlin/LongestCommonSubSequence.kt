/**
 *  Algorithm: Longest Common Sub-Sequence using Dynamic Programming
 *  Language: Kotlin
 *  Input:
 *      String1 and String2 -> Two Strings
 *  Output:
 *      Integer -> The longest common sub-sequence of String1 and String2
 *  Time Complexity: O(nStr1*nStr2)
 *  Space Complexity: O(nStr1*nStr2)
 *
 *  Sample Input:
 *      Enter the first String:
 *          AGGTAB
 *      Enter the second String:
 *          GXTXAYB
 *
 *  Sample Output:
 *      The length of longest common sub-sequence is:
 */

import kotlin.math.max

class LongestCommonSubSequence {
    fun longestCommonSubSequence(str1: String, str2: String): Int {
        val nStr1 = str1.length
        val nStr2 = str2.length
        val dp = Array(nStr1 + 1) { IntArray(nStr2 + 1) }

        (1 until nStr1 + 1).forEach { i ->
            (1 until (nStr2 + 1)).forEach { j ->
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                }
            }
        }
        return dp[nStr1][nStr2]
    }
}

fun main() {
    println("Enter the first string: ")
    val string1 = readLine()!!
    println("Enter the second string: ")
    val string2 = readLine()!!

    val lcs = LongestCommonSubSequence()
    println("The length of longest common sub-sequence is: ${lcs.longestCommonSubSequence(string1, string2)}")
}
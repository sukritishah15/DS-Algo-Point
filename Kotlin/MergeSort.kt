/**
 *  Algorithm: Merge Sorting
 *  Language: Kotlin
 *  Input:
 *   a) n: Size of Array
 *   b) arr: Integer Array of size n
 *  Output:
 *   a) Array before applying Merge Sorting
 *   b) Array after applying Merge Sorting
 *  Time Complexity: O(n * log n)
 *  Space Complexity: O(n)
 *
 *  Sample Input:
 *  Enter the size of the integer array:
 *  5
 *  Enter an integer array:
 *  5 4 8 2 1
 *
 *  Sample Output:
 *  Array before sorting is:
 *  5 4 8 2 1
 *  Array after sorting is:
 *  1 2 4 5 8
 */


import MergeSort.Companion.printIArray
import java.util.*

class MergeSort {
    fun mergeSort(array: IntArray) {
        val n = array.size
        if (n < 2) return
        val mid = n / 2
        val left = IntArray(mid)
        val right = IntArray(n - mid)
        for (i in 0 until mid) left[i] = array[i]
        for (i in mid until n) right[i - mid] = array[i]
        mergeSort(left)
        mergeSort(right)
        merge(left, right, array)
    }

    private fun merge(left: IntArray, right: IntArray, array: IntArray) {
        val nLeft = left.size
        val nRight = right.size
        var i = 0
        var j = 0
        var k = 0
        while (i < nLeft && j < nRight) {
            if (left[i] <= right[j]) {
                array[k] = left[i]
                k++
                i++
            } else {
                array[k] = right[j]
                k++
                j++
            }
        }
        while (i < nLeft) {
            array[k] = left[i]
            i++
            k++
        }
        while (j < nRight) {
            array[k] = right[j]
            j++
            k++
        }
    }

    companion object {
        fun printIArray(array: IntArray) {
            println(array.joinToString(" "))
        }
    }
}

fun main() {
    val scanner = Scanner(System.`in`)
    println("Enter the size of the integer array: ")
    val n = scanner.nextInt()
    println("Enter an integer array: ")
    val arr = IntArray(n)
    arr.indices.forEach {
        arr[it] = scanner.nextInt()
    }
    val merge = MergeSort()
    println("Array before sorting is: ")
    printIArray(arr)
    merge.mergeSort(arr)
    println("Array after sorting is: ")
    printIArray(arr)
}
/**
 *  Algorithm: Diameter of Binary Tree
 *  Language: Kotlin
 *  Input:
 *      Sample Binary Tree
 *  Output:
 *      Diameter of Binary Tree
 *  Time Complexity: O(n) as we are visiting every node once.
 *  Space Complexity: O(d) where d is the depth of the binary tree
 *
 *  Sample Input:
 *          8
 *        /   \
 *      3      10
 *    /  \       \
 *   1    6       14
 *      /  \     /
 *     4   7   13
 *
 *  Sample Output:
 *  Diameter of Binary Tree: 6
 */

import kotlin.math.max

class BinaryTree(var value: Int) {
    var leftChild: BinaryTree? = null
    var rightChild: BinaryTree? = null
}

class DiameterBinaryTree {
    private fun dfs(root: BinaryTree?): Pair<Int, Int> {
        if (root == null) {
            return Pair(0, 0)
        }
        val leftChild = dfs(root.leftChild)
        val rightChild = dfs(root.rightChild)
        val diameter = max(leftChild.first, max(rightChild.first, leftChild.second + rightChild.second))
        return Pair(diameter, max(leftChild.second, rightChild.second) + 1)
    }

    fun diameterOfBinaryTree(root: BinaryTree?): Int {
        return dfs(root).first
    }
}

fun main() {
    val tree = BinaryTree(8)
    tree.leftChild = BinaryTree(3)
    tree.rightChild = BinaryTree(10)
    tree.leftChild?.leftChild = BinaryTree(1)
    tree.leftChild?.rightChild = BinaryTree(6)
    tree.leftChild?.rightChild?.leftChild = BinaryTree(4)
    tree.leftChild?.rightChild?.rightChild = BinaryTree(7)
    tree.rightChild?.rightChild = BinaryTree(14)
    tree.rightChild?.rightChild?.leftChild = BinaryTree(13)

    val diam = DiameterBinaryTree()
    val diameter = diam.diameterOfBinaryTree(tree)
    println("Diameter of Binary Tree: $diameter")
}

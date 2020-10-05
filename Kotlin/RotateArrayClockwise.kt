/*
Problem: Rotated an array by given k elements in clockwise manner.

Sample I/O:

Enter size of array:5
Enter array elements:1 2 3 4 5
Enter Number of roatations:2
Rotated array is 
4 5 1 2 3

Time Complexity: O(n*d)
Space Complexity : O(1)

*/

fun main() {
        println("Enter size of array");
        var n=readLine()!!.toInt();
        println("Enter Array Elements");
        var arr=readLine()!!.split(" ").map { it.toInt() }.toTypedArray();
        println("Enter Number of Rotations");
        var d=readLine()!!.toInt();
    
        LeftRotateArray(arr, n, d)

        for(i in arr){
            print("$i ");
        }
        println();
}


private fun LeftRotateArray(arr:Array<Int>,n:Int,d:Int){

    for(i in 0..d-1){
        var temp=arr[0];
        for( j in 0..n-2){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }

}

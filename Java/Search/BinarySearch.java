package Java.Search;

/**
Implementation of Binary Search in Java
https://github.com/sukritishah15/DS-Algo-Point/issues/63
Contributed by @jhoserpacheco : https://github.com/jhoserpacheco
*/

public class BinarySearch(){

    public int binary_search(int array[], int x){
    	int l = 0, r = array.length - 1;
    	while (l <= r) {
    		int m = (l + r) / 2;
    		if(array[m] < x) l = m + 1;
    		else if (array[m] > x) r = m - 1;
    		else return m;
    	}
    	return -1;
    }


}

/*

Sample I/O-

Input -
Array = {5,3,4,1,2,8,9} |  search: 1
Ouput - 3
Time Complexity - O(log(n))
Space Complexity - O(n)

*/

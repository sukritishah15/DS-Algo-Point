import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;
import java.io.File;

public class InsertionSort{
    
    void sorting(ArrayList<Integer> arr)
	{
		 int n = arr.size();
		 for (int i = 1; i < n; i++) {
            //int element = arr.get(i);
            for (int j = i; j > 0; j--){
                int e1 = arr.get(j);
                int e2 = arr.get(j-1);
				if (e2 > e1){
			        arr.set(j, e2);
                    arr.set(j-1,e1);
                }
            }
        }		        
    }
    
	public static void main(String args[]) throws IOException
	{
        InsertionSort obj = new InsertionSort();
        String pathToFile = "./Sorting/unsorted.txt";
        File unsorted = new File(pathToFile);
        Scanner sc = new Scanner(unsorted);
        sc.useDelimiter(",");
        ArrayList<Integer> arr = new ArrayList<Integer>();
        while(sc.hasNext()){
            arr.add(sc.nextInt());
        }
		obj.sorting(arr);
        System.out.println("Sorted array");
		
        System.out.println( arr);
        sc.close();
	}


}

package Java.Sorting;

class quick_sort{

/* placing the pivot element in the correct position such that elements less than pivot will be on left and elements greater than pivot will be on right of the array */

int partition(int a[],int l, int h)
{
    int pivot = a[h];
    int i= (l-1); //smaller element index
    for(int j=l ; j<h ;j++)
      {
    	 if(a[j] < pivot)
          {
             i++;
             int temp = a[i];
	     a[i] = a[j];
             a[j] = temp;
           }


       }
int temp = a[i+1];
a[i+1] = a[h];
a[h] = temp;

return i+1;
    
}

void q_sort(int a[],int l,int h)
{
   if(l < h)
     {

            int p = partition(a,l,h);
        //sorting elements through recursion
            q_sort(a,l,p-1);
 	    q_sort(a,p+1,h);

      }


}

static void print_array(int a[])
{
   int n = a.length;
   for(int i=0;i<n;i++)
   {
        System.out.print(a[i]+" ");
        System.out.print("\t");
    }
}

public static void main(String args[])
{
    int a[] = {3,5,2,1,4};
    int n = a.length;
    quick_sort q = new quick_sort();
    q.sort(a,0,n-1);
    System.out.println("Sorted Array ");
    print_array(a);
}

}

/*  

Implementation of Quick Sort in Java 


Sample I/O-

Input - {3,5,2,1,4}
Output - Sorted Array 1 2 3 4 5

Time Complexity - O(nlog(n))
Space Complexity - O(n)

*/        



package Java.Sorting;

import java.util.Scanner;
import java.util.Arrays;


public class RadixSort {

    public static int getMax(int n,int[] x)
    {   
        int max=x[0];
        for(int i=0;i<n;i++)
        { 
            if(x[i]>max)
            {
                max=x[i];
            }
        }
        return max;           //returning the maximum value of the array
    }

    public static void radixSort(int n,int[] x)
    {
       int max=getMax(n,x);
       for(int pos=1;(max/pos)>0;pos*=10)    //pos is place(ones,tens,hundred...) of the number which is going to sort .
       {
         count(n,x,pos);
       }
     }
   public static void count(int n,int[] x,int pos)
   {
       int [] temp=new int[n]; 
       int [] count=new int[10]; //here length of array is 10 because in single digit number range goes from (0-9) total 10 digits
       Arrays.fill(count, 0);//initilizing the value of all element in count to zero
     for(int i=0;i<n;i++)
     {
         count[(x[i]/pos)%10]++;
     }
     for(int i=1;i<10;i++)
     {
       count[i]= count[i]+count[i-1];  //using count-sort algorithm
     }
     for(int i=n-1;i>=0;i--)
     {
         temp[count[(x[i]/pos) %10 ]-1]=x[i];
         count[(x[i]/pos)%10]--;
     }
     for(int i=0;i<n;i++)
     {
         x[i]=temp[i];       
     }

   }

   public static void print(int n,int []x)
   {
       for(int i=0;i<n;i++)
       {
           System.out.print(x[i]+" ");
       }
   }

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array :");
        int n=sc.nextInt();
        int[] x=new int[n];
        System.out.println("Enter the elements of array : ");
        for(int i=0;i<n;i++)
        {
            x[i]=sc.nextInt();
        }
        
        radixSort(n,x);
        System.out.println("Sorted array is :");
        print(n,x);
        

    
    }
    
}

/*Implement of radix sort 
Input/Output Format
Input
enter no. of elements in array
elements of array
Output 
Sorted array

Example suppose array is {30,2,450,33,3}
Output is {2,3,30,33,450}
Complexities
Time Complexity is:O(d*(n+b)) 
                    d:no. of digits of max number in Array
                    n:no. of Elements
                    b:base (here is 10)
Space Complexity is:O(n+2^d)    */                    

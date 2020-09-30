#include<stdio.h>

 
 int main()
 {
     int n; //size of an array
     printf("Enter the size of array: ");
     scanf("%d",&n);
     int arr[n];  //Declaration of array
     printf("Enter the elements of array: ");
     for(int i=0;i<n;++i)
     {
         scanf("%d", &arr[i]);
     }
//   Bubble sort function
  for(int i=0;i<(n-1);++i)
 {  
    for(int j=0;j<(n-1-i);++j)
    {    int temp=0;
        if(arr[j]>arr[j+1])
        { //Swap between arr[j] and arr[j+1]
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp; 
        
        }

    }
  }

  // printing sorted array
  printf("Sorted array is: ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
 return 0;

 }


/* Implementing bubble sort
 I/O 
 Input
 Enter the size of array:
 Enter the elements of array:

 Ouput 
 Sorted array is:


 Example 1:Suppose the size of array is 6
           Elements are : 1 9 5 43 34 99

           Output is=> 1 5 9 34 43 99

 Example 2:Suppose the size of array is 9
           Elements are :99 67 56 2 45 88 45 1 3 90

           Output is=> 1 2 3 45 45 56 67 90 99          



Time Complexity:O(n^2)
Space Complexity:O(1)
*/

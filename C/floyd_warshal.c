#include<stdio.h>
int i, j, k,n,arr[10][10];
//Floyd function 
void floyd_Warshell ()
{
 //Add all vertex one by one
    for (k = 0; k < n; k++)
    {
	//pick all as a source
        for (i = 0; i < n; i++)
        {
	    //pick all as a destination
            for (j = 0; j < n; j++)
            {
                if ((arr[i][k] * arr[k][j] != 0) && (i != j))
                {
		    //If vertex k is on the shortest path from  
                    // i to j, then update the value of arr[i][j] 
                    if ((arr[i][k] + arr[k][j] < arr[i][j]) || (arr[i][j] == 0))
                    {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
    }
}
//Main function Began
int main()
{
  int i,j;
  //Enter the number of vertex
  printf("enter no of vertices :");
  scanf("%d",&n);
  printf("\n");
 //Enter values for array
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   {
    printf("arr[%d][%d]:",i,j);
    scanf("%d",&arr[i][j]);
   }
 //call Floyd function
 floyd_Warshell();
 //OUTPUT
 printf("OUTPUT");
 //print the output
 printf (" \n\n Shortest distances are :\n");
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
   printf ("%d\t", arr[i][j]);
  printf("\n");
 }
 return 0;
}
//main function ends

/*Sample Input Output :
enter no of vertices :4

dist[0][0]:0
dist[0][1]:8
dist[0][2]:999
dist[0][3]:1

dist[1][0]:999
dist[1][1]:0
dist[1][2]:1
dist[1][3]:999

dist[2][0]:4
dist[2][1]:999
dist[2][2]:0
dist[2][3]:999

dist[3][0]:999
dist[3][1]:2
dist[3][2]:9
dist[3][3]:0

OUTPUT

 Shortest distances are :
0	3	4	1	
5	0	1	6	
4	7	0	5	
7	2	3	0	

Time Complexity :O(N^3)

*/

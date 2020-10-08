#include<bits/stdc++.h>
using namespace std;
void floyd_waeshall(int arr[][5])
{
    int i, j, k;
   //Add all vertex one by one
    for (k = 0; k < 5; k++)
    {
	//pick all as a source
        for (i = 0; i < 5; i++)
        {
	    //pick all as a destination
            for (j = 0; j < 5; j++)
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
   //function to print solution
    cout<<"\nOUTPUT"<<endl;
    for (i = 0; i < 5; i++)
    {
        cout<<"\nMinimum Cost for Node: "<<i<<endl;
        for (j = 0; j < 5; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
 
    }
}
//Main function begain
int main()
{
    int a[5][5];
    //Enter values
    cout<<"Enter values for matrix-\n\n";
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter values for "<<(i+1)<<" row :"<<endl;
        for (int j = 0; j < 5; j++)
        {
            cin>>a[i][j];
        }
    }
    // call the floyd function
    floyd_waeshall(a);
}
//main function ends

/*Sample Input Output :
Enter values for matrix-

Enter values for 1 row :
0
3
6
0
0
0
0
Enter values for 2 row :
3
0
2
4
0
0
0
Enter values for 3 row :
6
2
0
1
4
2
0
Enter values for 4 row :
0
4
1
0
2
0
4
Enter values for 5 row :
0
0
4
2
0
2
1

OUTPUT
Minimum Cost for Node: 0
0	3	6	6	5	
Minimum Cost for Node: 1
5	0	3	3	2	
Minimum Cost for Node: 2
4	7	0	7	6	
Minimum Cost for Node: 3
2	5	1	4	2	
Minimum Cost for Node: 4
3	6	2	1	0	

Time Complexity :O(N^3)

*/
#include<iostream>
using namespace std;
int main()
{
    long long int sum,n,i,j,k;
    cin>>sum>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int b[n+1][sum+1];
    for(i=0;i<=n;i++)
    {
        b[i][0]=1;
    }
    for(i=0;i<=n;i++)
    {
        if(i==0)
        {
        for(j=1;j<sum+1;j++)
        {
            b[0][j]=0;
        }
        }
        else
        {
            for(j=1;j<sum+1;j++)
            {
                if(j<a[i-1])
                {
                    b[i][j]=b[i-1][j];
                }
                else
                {
                    b[i][j]=b[i-1][j]+b[i][j-a[i-1]];
                }
            }
        }
    }
    cout<<b[n][sum];
}

/* Sample input:  4 3
                  1 2 3
   Sample output: 4
 */
/* Time complexity is O(sum*n)
   Space complexity is O(n)
*/

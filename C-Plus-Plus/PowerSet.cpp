#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
class set
{
	int *a,n;
	public:
		void getdata()
		{
			cout<<"Enter number of elements of set: ";
			cin>>n;
			a = new int[n];
			cout<<"Enter elements of set: ";
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
		}
		void unique()
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i]==a[j])
					{
						for(int k=j+1;k<n;k++)
						{
							a[k-1]=a[k];
						}
						j--;
						n--;
					}
				}
			}
			cout<<"After removing duplicate elements: ";
			for(int i=0;i<n;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		
		void power()
		{
			unique();
			int h=pow(2,n);
			cout<<"Power set is: ";
			for(int i=0;i<h;i++)
			{
				cout<<"{";
				for(int j=0;j<n;j++)
				{
					if(i&(1<<j))
					cout<<a[j];
				}
				cout<<"}"<<endl;
			}
		}
};
int main()
{
	set r1;
	r1.getdata();
	r1.power();
	getch();
	return 0;
}

/*
OUTPUT:
Sample input:
Enter number of elements of set: 3
Enter elements of set: 1 2 3
output:
After removing duplicate elements: 1 2 3
Power set is: {}
{1}
{2}
{12}
{3}
{13}
{23}
{123}
*/

/* Time complexity of unique() is = O(n^3)
and Time complexity of power() is = O(n^3)
and time complexity of getdata() is = O(n)
therefore overall time complexity is  = O(n^3) + O(n^3) + O(n) = O(n^3)
*/ 

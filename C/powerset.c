#include<stdio.h>
#include<math.h>
#include<conio.h>

void generatepowerset(int n, int *set){
	//printing of power set//
	int i, j;
	printf("{");
	for(i=0; i<pow(2,n); i++)
	{
		for(j=0; j<n; j++)
		{
			if(i&(1<<j))
			{
				printf("%d", set[j]);
			}
			
		}
		printf(",");
	}
		printf("}");
}

int main()
{
	int i, j, n;
	printf("Enter no. of elements in the set= ");
	scanf("%d", &n);
	int set[n];
	printf("Enter elements = ");
	//size of power set pow(2, n)//
	for(i=0; i<n; i++)
	{
		scanf("%d", &set[i]);
	}
	
	generatepowerset(n, set);
	return 0;
}

/*
input:Enter no. of elements in the set= 3
 	  Enter elements= 123
output: {, 1,2,3,12,13,23,123}

T.C: theta(n*2^n)
S.C: theta(n)
*/

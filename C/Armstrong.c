#include<stdio.h>
#include<math.h>

int main()
{
	int flag=1;
	long long int no, summ=0, length=0,temp1,temp2,remainder=0;
	printf("Enter the number: ");
	scanf("%d",&no);
	temp1=no;
	temp2=no;
	while(temp1!=0)
	{
	    length+=1;
        temp1=temp1/10;
	}
	
	while(temp2!=0)
	{
		remainder=temp2%10;
        summ+=pow(remainder,length);
        temp2=temp2/10;
	}
	
	if(summ == no)
	{
		printf("%d is an armstrong number.", no);
	}
    else if (summ != no)
    {
    	printf("%d is not an armstrong number.", no);
	}
	return 0;
}

/*
Input:
Enter the number: 153

Output:
153 is an armstrong number.

--------------------------------

Input:
Enter the number: 135

Output:
135 is not an armstrong number.

--------------------------------

Complexity
Worst case time complexity: O(log(n))
Average case time complexity: O(log(n))
Best case time complexity: O(log(n))
Space complexity: O(1)
The complexity is O(log N) as in a number N, there are log N digits and we are assuming power takes constant time.

In fact, raising a number M to the power K takes O(log K * log M) time.In our case, M is limited between 0 to 9 so,
we can consider the overall complexity of our algorithm to be O(log N * log K) where N is the number to be checked and K is the number of digits in the number.
*/

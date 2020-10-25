#include<stdio.h>
#include<conio.h>
void main()
{
int a,b;
clrscr();
printf("Enter the first element: ");
scanf("%d",&a);
printf("Enter the second element: ");
scanf("%d",&b);
a=a+b;
b=a-b;
a=a-b;
printf("Element after swapping: \n");
printf("First element is %d",a);
printf("Second element is %d",b);
}


/*Swapping of element without third variable
  I/O
  Input:enter the first and second element
  Output:Element are swapped are shown

Example:first element is:5
        second element is:6
        output=> first is 6
                 second is 5

Time Complexity:O(1);
Space Complexity:O(1);
*/

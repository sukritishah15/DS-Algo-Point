#include<stdio.h>
#include<math.h>

int main()
{
    float x1,y1;                                // declaring variables for first point
    float x2,y2;                                // declaring variables for second point
    double dist;                                // variable to store distance
    double slope;                               // variable to store slope
    int n;                                      // variable to input choice
    char ch;                                    // variable to input user choice
    printf("Input x1: ");                       // input points
	scanf("%f", &x1);
	printf("Input y1: ");
	scanf("%f", &y1);
    printf("Input x2: ");
	scanf("%f", &x2);
	printf("Input y2: ");
	scanf("%f", &y2);
    dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));   // using distance formula
    slope=(y2-y1)/(x2-x1);                      // using slope formula
    do
    {
        printf("Select operation to perform."); // inputting user choice
        printf("\n1.Distance between two points\n2.Slope of line\n3.Equation of line between to points ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("\nDistance between two points is: %lf",dist);
                break;
            case 2:
                printf("\nSlope of line is: %lf",slope);
                break;
            case 3:
                printf("\nEquation of line is: ");
                printf("\ny = %f + %lf(x-%f)",y1,slope,x1);
                break;
            default:
                printf("\nInvalid input.");
        }
        printf("\n\nDo you want to continue? y/n ");
        scanf("%s",&ch);
    }while(ch=='y');
    return(0);

    /*
    
    Output:
    Input x1: 3
    Input y1: 4
    Input x2: 7
    Input y2: 8
    Select operation to perform.
    1.Distance between two points
    2.Slope of line
    3.Equation of line between to points 1

    Distance between two points is: 5.656854

    Do you want to continue? y/n y
    Select operation to perform.
    1.Distance between two points
    2.Slope of line
    3.Equation of line between to points 2

    Slope of line is: 1.000000

    Do you want to continue? y/n y
    Select operation to perform.
    1.Distance between two points
    2.Slope of line
    3.Equation of line between to points 3

    Equation of line is: 
    y = 4 + 1(x-3)

    Do you want to continue? y/n n
     
    Time Complexity = O(1)
    Space Complexity = O(1)
    */


}

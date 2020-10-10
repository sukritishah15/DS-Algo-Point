#include <stdio.h>
#define ops 4

float sum(float a, float b){return a+b;}
float sub(float a, float b){return a-b;}
float div(float a, float b){return a/b;}
float mul(float a, float b){return a*b;}

int main()
{
    float (*ptr[ops])(float,float) = {sum,sub,div,mul};
    int choice;
    float a,b;
    printf("Enter 0 for sum,1 for sub,2 for div, 3 for mul: \n");
    scanf("%d", &choice);
    printf("Enter the two numbers \n");
    scanf("%f %f", &a, &b);
    printf("%f",ptr[choice](a, b));
    return 0;
}

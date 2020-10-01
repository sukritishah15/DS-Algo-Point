#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char string[100];
    printf("Enter expression:");
    scanf("%s",string);
    int i, top = -1, flag=1;
    char stack[100];
    for(i=0; i<strlen(string); i++)
    {
        if((string[i] == '{') || (string[i] == '[') || (string[i] == '('))
        {
            top++;
            stack[top] = string[i];
        }
        else if((string[i] == '}') || (string[i] == ']') || (string[i] == ')'))
        {
            if(top == (-1))
            {
                flag =0;
                break;
            }
            else
            {
                if(string[i] == '}')
                {
                    if(stack[top] == '{')
                    {
                        top--;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                else if(string[i] == ']')
                {
                    if(stack[top] == '[')
                    {
                        top--;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                else if(string[i] == ')')
                {
                    if(stack[top] == '(')
                    {
                        top--;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
            }
        }
    }
    if((flag == 1) && (top == -1))
    {
        printf("Expression is balanced");
    }
    else
    {
        printf("Expression is not balanced");
    }
}

/*
Problem: Given a string expression, check whether the pair and order of { }, ( ),[ ] are correct in expression.

Sample I/O:

Enter expression:{{()[]}
Expression is not balanced

Enter expression:{}[]()
Expression is balanced

Enter expression:{([])}
Expression is balanced

Space Complexity: O(n) (worst case when there is no closing bracket in expression)
Time Complexity:O(n) where n is length of expression.
*/

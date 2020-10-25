#include <bits/stdc++.h>
using namespace std;
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2);
}
int main()
{
    cout<<"Enter coordinates of triangle:"<<endl;
    double x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<"Enter number to be checked:";
    double x, y;
    cin>>x>>y;
    if(area(x1, y1, x2, y2, x3, y3) == (area(x, y, x2, y2, x3, y3) + area(x1, y1, x, y, x3, y3) + area(x1, y1, x2, y2, x, y)))
    {
        cout<<"Point lies inside the trianle"<<endl;
    }
    else
    {
        cout<<"Point lies outside the triangle"<<endl;
    }
    return 0;
}

/*
Problem: Check if a given point lies inside a given triangle.

Sample I/O:

Enter coordinates of triangle:
0 0
0 4
4 0
Enter number to be checked:3 3
Point lies inside the trianle

Enter coordinates of triangle:
0 0
0 4
4 0
Enter number to be checked:5 5
Point lies outside the triangle

Time Complexity: O(1)
Space complexity: O(1)
*/

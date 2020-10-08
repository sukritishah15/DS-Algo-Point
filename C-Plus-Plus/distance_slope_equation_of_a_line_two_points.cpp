#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x1,y1;//Declare variables for first point (x1,y1)
    double x2,y2;//Declare variables for second point (x2,y2)
    double distance;//To store the euclidean distance between two points. D = sqrt(pow((x2-x1),2) + pow((y2-y1),2))
    double slope;// To store the slope of the line formed by two points
    cin>>x1>>y1;//Enter first point
    cin>>x2>>y2;//Enter second point
    distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));//Stored the distance from the formula given above
    slope = (y2 - y1)/(x2 - x1);
    cout<<"The Distance between the points ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<") is : "<<distance<<endl;
    cout<<"The slope between the line formed by the points ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<") is : "<<slope<<endl;
    cout<<"The equation of the line is"<<endl;
    cout<<"y = "<<y1<<" + "<<slope<<"(x - "<<x1<<")"<<endl;
    /*
    Sample Input
    3 4
    6 7
    Output
    The Distance between the points (3,4) and (6,7) is : 4.24264
    The Slope between the points (3,4) and (6,7) is : 1
    The equation of the line is
    y = 4 + 1(x-3)

    Time Complexity = O(1)
    Space Complexity = O(1)
    */
}
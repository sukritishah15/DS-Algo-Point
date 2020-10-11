package Java.Algorithms;

import java.lang.Math;

class approxing_pi{
  public static void main(String[] args){
    long itr=(long)(10000000000.0);
    
    double x=Math.random();
    double y=Math.random();

    long point_circle=0; 
    long point_square=0;

    for(long i=0;i<itr;i++){     
      x=Math.random();
      y=Math.random();
      if((x*x+y*y)<=1)
        point_circle++;
      point_square++;
    }

    double pi=4.0*((double)point_circle/point_square);

    System.out.println("value of Pi approximated "+pi);

  }
}
/*
Genrating a co-ordinate and chekcing if it exist in circle or not.Then taking ratio of 
number of point existing in circle out of total. this gives probabilty of hitting a 
circle out of square consisting it this is compared with theoretical value that is 
possibility found by area we find the constant value of pi.higher the number of points 
considered higher accuracy in finding vallue of pi.


Implimentation:
  gentating randon number for x and y
  checking if it exist in unit circle

Input:
  NONE

output:
  approximated pi value

Sample Input-Output:
  Input1:
    NONE
  Output1:
  	value of Pi approximated 3.1416003972

Time Complexity= O(itr)
space Complexity= O(1)

Contributed by : Hitansh K Doshi(github id: Hitansh159)
*/
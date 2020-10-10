import java.util.Scanner;

import static java.lang.Math.sqrt;
import static java.lang.StrictMath.pow;

public class EqOfLine {
    private static Scanner scanner=new Scanner(System.in);
    public static void main(String[] args) {
        double x1;
        double y1;//Declare variables for first point (x1,y1)
        double x2;
        double y2;//Declare variables for second point (x2,y2)
        double distance;//D = sqrt(pow((x2-x1),2) + pow((y2-y1),2))
        double slope;// slope of the line formed by two points
//
        x1=scanner.nextInt();
        scanner.nextLine();
        x2=scanner.nextInt();
        scanner.nextLine();
        y1=scanner.nextInt();
        scanner.nextLine();
        y2=scanner.nextInt();
        scanner.nextLine();

        distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));//Stored the distance from the formula given above
        slope = (y2 - y1)/(x2 - x1);
        System.out.println("The Distance between the points ("+x1+","+y1+") and ("+x2+","+y2+") is : "+distance);
        System.out.println("The slope between the line formed by the points ("+x1+","+y1+") and ("+x2+","+y2+") is : "+ slope);
        System.out.println("The equation of the line is");
        System.out.println("y = "+y1+" + "+slope+"(x - "+x1+")");
    }
}

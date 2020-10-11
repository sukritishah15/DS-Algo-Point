package Java.Algorithms;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Point{
    public void setXY(int x,int y) {
        this.x = x;
        this.y=y;
    }
    int x,y;
}

class SortByY implements Comparator<Point>{
    public int compare(Point p1, Point p2){
        return p2.y-p1.y;
    }
}

class SortByx implements Comparator<Point>{
    public int compare(Point p1, Point p2){
        return p2.x-p1.x;
    }
}

public class closestPair {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of pairs of points: ");
        int n = sc.nextInt();
        System.out.println("Enter the points in seperated by space (like x y): ");
        Point[] pts = new Point[n];
        for(int i = 0;i<n;i++){
            pts[i]= new Point();
        }
        for(int i = 0;i< n;i++) {
            int x, y;
            x = sc.nextInt();
            y = sc.nextInt();
            pts[i].setXY(x, y);
        }
        Arrays.sort(pts,new SortByx());
        System.out.println(closest(pts,n));
    }
    public static double dist(Point p1,Point p2){
        return Math.sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    }

    public static double bruteForce(Point[] P,int n){
        double mini = Double.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dist(P[i], P[j]) < mini)
                    mini = dist(P[i], P[j]);
            }
        }
        return mini;
    }
    public static double stripClose(Point[] strip,int n,double dis){
        double minm = dis;
        Arrays.sort(strip,new SortByY());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minm; ++j) {
                if (dist(strip[i], strip[j]) < minm)
                    minm = dist(strip[i], strip[j]);
            }
        }
        return minm;
    }
    public static double closest(Point[] pts, int n){
        if(n<=5)
            return bruteForce(pts, n);
        int mid = n/2;
        Point midPoint = pts[mid];
        double leftDist = closest(pts,mid);
        double rightDist = closest(Arrays.copyOfRange(pts,mid,pts.length),n-mid);
        double d = Math.min(leftDist,rightDist);

        Point[] strip = new Point[n];
        for(int i =0;i<n;i++)
            strip[i]= new Point();
        int j =0;
        for(int i =0;i<n;i++){
            if(Math.abs(pts[i].x-midPoint.x)<d){
                strip[j] = pts[i];
                j++;
            }
        }
        return Math.min(d,stripClose(strip,j,d));
    }
}

/* Input : 2 3 , 12 30 , 40 50 , 5 1, 12 10, 3 4
   Output: 1.41
   Time: O(n(logn)^2)
   Space: O(n) */

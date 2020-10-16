public class PointInTriangle {
    // Calculate area of triangle and small triangles within
    public static double calculateArea(double triangle_x1, double triangle_y1,
                                       double triangle_x2, double triangle_y2,
                                       double triangle_x3, double triangle_y3) {
        return Math.abs((triangle_x1*(triangle_y2-triangle_y3) +
                triangle_x2*(triangle_y3-triangle_y1) +
                triangle_x3*(triangle_y1-triangle_y2))
                /2.0);
    }
    // Calls the calculateArea() function and determines if the point is within or not
    public static boolean isInside(double point_x, double point_y,
                                   double triangle_x1, double triangle_y1,
                                   double triangle_x2, double triangle_y2,
                                   double triangle_x3, double triangle_y3) {

        double areaOfTriangle = calculateArea(triangle_x1, triangle_y1,
                triangle_x2, triangle_y2,
                triangle_x3, triangle_y3);

        double areaOfTriangleSplit1 = calculateArea(point_x, point_y,
                triangle_x2, triangle_y2,
                triangle_x3, triangle_y3);

        double areaOfTriangleSplit2 = calculateArea(triangle_x1, triangle_y1,
                point_x, point_y,
                triangle_x3, triangle_y3);

        double areaOfTriangleSplit3 = calculateArea(triangle_x1, triangle_y1,
                triangle_x2, triangle_y2,
                point_x, point_y);

        if (areaOfTriangleSplit1 + areaOfTriangleSplit2 + areaOfTriangleSplit3 == areaOfTriangle) {
            return true;
        }
        return false;
    }
    // Main function
    public static void main(String[] args) {
        System.out.println(isInside(10, 15, 0, 0, 10, 30, 20, 0));
        System.out.println(isInside(30, 15, 0, 0, 10, 30, 20, 0));
    }

    /*
    Sample I/O:

    Input: 10, 15, 0, 0, 10, 30, 20, 0
    Output: true

    Input: 30, 15, 0, 0, 10, 30, 20, 0
    Output: false

    Time Complexity: O(1)
    Space Complexity: O(1)
     */
}

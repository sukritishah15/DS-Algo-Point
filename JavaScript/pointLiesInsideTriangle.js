/*
@Author Meena R G
*/ 
// Program is to calculate the given point lies inside triangle
//Calculate the area of triangle
const calculateArea=(triangle_x1, triangle_y1,
                    triangle_x2,  triangle_y2,
                    triangle_x3,  triangle_y3) => {
            return Math.abs((triangle_x1*(triangle_y2-triangle_y3) +
                            triangle_x2*(triangle_y3-triangle_y1) +
                            triangle_x3*(triangle_y1-triangle_y2))
                            /2.0)
   }
   
//To check the given point is inside the triangle
const isInside=(point_x, point_y, triangle_x1, triangle_y1,
    triangle_x2, triangle_y2,
    triangle_x3, triangle_y3) => {

    let areaOfTriangle = calculateArea(triangle_x1, triangle_y1,
        triangle_x2, triangle_y2,
        triangle_x3, triangle_y3);

    let areaOfTriangleSplit1 = calculateArea(point_x, point_y,
        triangle_x2, triangle_y2,
        triangle_x3, triangle_y3);

    let areaOfTriangleSplit2 = calculateArea(triangle_x1, triangle_y1,
        point_x, point_y,
        triangle_x3, triangle_y3);

    let areaOfTriangleSplit3 = calculateArea(triangle_x1, triangle_y1,
        triangle_x2, triangle_y2,
        point_x, point_y);

    if (areaOfTriangleSplit1 + areaOfTriangleSplit2 + areaOfTriangleSplit3 === areaOfTriangle) {
        return true;
    }
    return false;
}

var result=isInside(10, 15, 0, 0, 10, 30, 20, 0);
console.log(result);

/*
    Sample I/O:
    Input: 10, 15, 0, 0, 10, 30, 20, 0
    Output: true
    Input: 30, 15, 0, 0, 10, 30, 20, 0
    Output: false
    Time Complexity: O(1)
    Space Complexity: O(1)

 */
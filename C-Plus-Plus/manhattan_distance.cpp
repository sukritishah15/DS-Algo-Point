/*
      The program has to prompt the user to enter the coordinates of the 2 points.
      Result should be the MANHATTAN Distance between the two points.
      Example :-
      Enter the coordinates of the first point:
      10 20
      Enter the coordinates of the second point:
      20 30
      Manhattan Distance between the two points is : 20

      ------------------------------------------------------------------------------
      SPACE COMPLEXITY - O(1) 
      TIME  COMPLEXITY - O(1) 
      ------------------------------------------------------------------------------
*/

#include <iostream> 
using namespace std;

int main() {
      cout << "Enter the coordinates of the first point:" << endl;
      int x1, y1; 
      cin >> x1 >> y1; 
      cout << "Enter the coordinates of the second point:" << endl; 
      int x2, y2; 
      cin >> x2 >> y2; 

      int manhattanDistance = abs(x1 - x2) + abs(y1 - y2); 
      cout << "Manhattan Distance between the two points is : " << manhattanDistance << endl;
}
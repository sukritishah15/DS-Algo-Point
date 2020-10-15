// X = Path
// Y = Wall
// W = FloodFill

const array = [
  ["X", "X", "X", "X", "X"],
  ["Y", "X", "Y", "X", "Y"],
  ["Y", "Y", "X", "X", "Y"],
  ["X", "Y", "Y", "Y", "Y"],
  ["X", "Y", "Y", "Y", "Y"],
];

const coordinates = [2, 2];

const height = array.length;
const width = array[0].length;

floodFill(coordinates[0], coordinates[1]);
console.log(array);

function floodFill(x, y) {
  if (x < 0 || y < 0 || x >= height || y >= width) return; //if coordinates are not valid stop
  if (array[x][y] === "Y" || array[x][y] === "W") return; //if it's wall or already visited stop

  array[x][y] = "W"; //set it to "W"

  //checks for surrounding pixels
  floodFill(x + 1, y);
  floodFill(x, y + 1);
  floodFill(x - 1, y);
  floodFill(x, y - 1);
}

/*
Input :  [
  ["X", "X", "X", "X", "X"],
  ["Y", "X", "Y", "X", "Y"],
  ["Y", "Y", "X", "X", "Y"],
  ["X", "Y", "Y", "Y", "Y"],
  ["X", "Y", "Y", "Y", "Y"],
]

Output : [ 
  [ "W", "W", "W", "W", "W" ],
  [ "Y", "W", "Y", "W", "Y" ],
  [ "Y", "Y", "W", "W", "Y" ],
  [ "X", "Y", "Y", "Y", "Y" ],
  [ "X", "Y", "Y", "Y", "Y" ]
 ]
*/

/*
Time Complexity : O(N)  N is number of total pixels
Space Complexity : O(N) 
*/

//check if given string is pangram or not

function checkPangram(givenString){
  givenString =  givenString.toLowerCase().replaceAll(" ",'');
  const count = new Set(givenString);
  if(count.size === 26) console.log("Given String is Pangram");
  else console.log("Given String is not Pangram");

}
givenString = "The quick brown fox jumps over the lazy dog"
checkPangram(givenString);

/*
Sample Test case 1:
    Input: 'abc'
    Output: Given String is not pangram

Sample Test case 2:
    Input: 'The quick brown fox jumps over the lazy dog'
    Output: Given String is pangram

Time Complexity : O(n)
Space Complexity : O(n)
*/
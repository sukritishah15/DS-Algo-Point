object SwapTwoNumbers{
	def main(args: Array[String]): Unit = {
	
        //Input
        var x = 2
        var y = 1
    
        //Display variables and values
 	    println("Before Swapping:") 
        println("x = "+x+", y = "+y) 

	    //Display an empty line
    	println("") 
  
        //Swap numbers
        x = x + y 
        y = x - y
        x = x - y
  
        //Display the vriables with their swapped value
        println("After Swapping:") 
        println("x = "+x+", y = "+y) 
 
        //Time Complexity: O(1)
        //Space Complexity: O(1)

        /*
        Sample I/O:
	        Before Swapping:
            x = 2, y = 1

            After Swapping:
            x = 1, y = 2         
        */
	}
}
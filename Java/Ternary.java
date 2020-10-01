//Program to illustrate the iterative approach to Ternary Search in Java

class Ternary { 

	
	static int ternarysrch(int left, int right, int key, int A[]) 

	{ 
		while (right >= left) { 

			
			int m1 = left + (right - left) / 3; 
			int m2 = right - (right - left) / 3; 

			
			if (A[m1] == key) { 
				return m1; 
			} 
			if (A[m2] == key) { 
				return m2; 
			} 

			

			if (key < A[m1]) { 

				
				right = m1 - 1; 
			} 
			else if (key > A[m2]) { 

				left = m2 + 1; 
			} 
			else { 

			 
				left = m1 + 1; 
				right = m2 - 1; 
			} 
		} 

		
		return -1; 
	} 

	
	public static void main(String args[]) 
	{ 
		int left, right, val, key; 

		
		int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 

		
		left = 0; 

		
		right = 9; 

		
		
		key = 5; 

		
		val = ternarysrch(left, right, key, A); 

		
		System.out.println("The Index of the specified" + key + " is : " + val); 

		 
	} 
} 



/**
 ** @author Meena R G
 */
public class CountOfPalindromeSubString {

	/*This function takes the string and length of string and 
	count the substring palindromes and return the count */

	public static int countPalindromeSubString(String str,int n) {
	
		if(str==null || str.length()==0) {
			return 0;
		}
		
		// arr[i][j ]true if substring str[i..j] is palindrome, else false 
		boolean[][] arr =new boolean[n][n];
		int count=str.length();
		
		// palindrome of single length
		for(int i=0;i<str.length();i++) {
			arr[i][i]=true;
		}
		
		// palindrome of length greater 1
		for(int i=n-2;i>=0;i--){
			for(int j=i+1;j<n;j++) {
				if(str.charAt(i)==str.charAt(j)) {
					if(arr[i+1][j-1] || j-1==1) {
						arr[i][j]=true;
						count++;
					}
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) {
		
		String str="bcacbf";
		System.out.println(countPalindromeSubString(str,str.length()));

	}

}

/*
input : bdcabf
output :8
input:cc
output:2
time complexity:O(n^2)
space complexity:O(n^2)
*/

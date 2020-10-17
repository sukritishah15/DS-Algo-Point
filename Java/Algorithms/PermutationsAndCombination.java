package Java.Algorithms;

public class PermutationsAndCombination {
    public static void main(String[] args) {
        System.out.println(factorial(1));
        System.out.println(Combinations(10, 1));
        System.out.println(Permutations(10, 5));

    }
    /**
     * This function return the factorial of parameter
     * the number passed to it
     * @param number
     * @return the factorial of number
     */
    public static int factorial(int number){
        if (number==0) {
            return 1;
        }
        return number*factorial(number-1);
    }
    /**
     * This function returns the permutions of given parameters.
     * @param n
     * @param r
     * @return the result of permutaions of r things out of n things
     */
    public static int Combinations(int n,int r){
        if(n>r){
            int comb=(factorial(n)/((factorial(r))*(factorial(n-r))));
            return comb;
        }
        System.out.println("Please make sure that n is greater than r ");
        return 0;
    }

    /**
     *
     * @param n
     * @param r
     * @return the permutations of r things out of n diffrent things;
     */
    public static int Permutations(int n, int r){
        if(n>r){
            return Combinations(n, r)*(factorial(r));
        }
        System.out.println("Please make sure that n is greater than r ");
        return 0;
    }

}

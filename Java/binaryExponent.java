import java.math.BigInteger;
import java.util.Scanner;

public class binaryExponent {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        long a=in.nextLong();
        long b=in.nextLong();
        System.out.println(power(a, b));
    }
    static BigInteger power(long a,long b)
    {
        BigInteger res=new BigInteger("1");
        BigInteger e=(new BigInteger(Long.toString(a)));
        while(b>0)
        {
            if((b&1)>0)
            {
                res=res.multiply(e);
            }
            e=e.multiply(e);
            b>>=1;
        }
        return res;
    }
    
}
/* Sample input:2 100
   Sample output:1267650600228229401496703205376
   
   time complexity:O(log n*log m)
   space complexity:O(log n)
   */

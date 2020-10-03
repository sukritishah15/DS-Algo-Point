import java.util.*;
class Factor
{
    public static void main(String[] args)

    {   
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = Integer.parseInt(sc.nextLine());


        int factor = 1;
        while(factor <= num)
        {
            if(num % factor == 0)
            {
                System.out.println(factor);
            }
            factor++;
        }


        sc.close();
    }
}

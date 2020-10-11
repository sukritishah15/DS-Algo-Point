package Java.Algorithms;

import java.util.Scanner;

public class SequenceAndSeries {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
      
      Scanner in=new Scanner(System.in);
      System.out.println("A MENU DRIVEN PROGRAM FOR MATHEMATICAL SEQUENCES AND SERIES");
      
      
      int z=1;
      while(z!=5)
      {
      System.out.println("1->HARMONIC SEQUENCE OPERATIONS");
      System.out.println("2-> ARITHMETIC SEQUENCE OPERATIONS");
      System.out.println("3->FIBONACCI SEQUENCE GENERATION");
      System.out.println("4->GEOMETRIC SEQUENCE OPERATION");
      System.out.println("ENTER YOUR CHOICE");
      z=in.nextInt();
      switch(z)
     {
         
         case 1:
             int ch1;
             System.out.println("ENTER 1 TO FIND NUMBER OF TERMS IN THE SEQUENCE");
             System.out.println("ENTER 2 TO FIND SUM FROM THE LAST GIVEN NUMBER OF TERMS");
              System.out.println("ENTER 3 TO FIND SUM FROM THE FIRST GIVEN NUMBER OF TERMS ");
              System.out.println("ENTER 4 TO FIND A TERM OF YOUR CHOICE");
              System.out.println("ENTER 5 TO PRINT SEQUENCE");
              ch1=in.nextInt();
             
             
             switch(ch1)
             {
                 case 1:
                     System.out.println("ENTER THE FIRST AND LAST TERMS OF THE SEQUENCE");
               double firstTerm = in.nextDouble();
	     double lastTerm = in.nextDouble();
             System.out.println("ENTER THE COMMON DIFFERENCE");
             int cd=in.nextInt();
                double a = 1/firstTerm;
		double b = 1/lastTerm;
		double ans = ((b - a)/cd)+1;
		System.out.println(ans);
                break;
                
                 case 2:
                     
                     System.out.println("ENTER LAST TERM ,COMMON DIFFERENCE AND THE TERM FROM WHICH YOU WANT THE SUM");
                    
	      lastTerm = in.nextDouble();
              cd=in.nextInt();
             double Term = in.nextDouble();
              
             double sum=0;
		 a = 1/lastTerm;
		for(int i=0; i<Term; i++)
		{
			 ans= a - i*cd;
			sum+=(double)1/(double)(ans);
		}
		System.out.println(sum);
             break;
                 case 3:
             System.out.println("ENTER FIRST TERM, COMMON DIFFERENCE AND THE TERM FROM WHICH YOU WANT THE SUM");
                     
	      firstTerm = in.nextDouble();
             
              cd=in.nextInt();
              Term = in.nextDouble();
              a = 1/firstTerm;
		 sum=0;
		for(int i=1; i<=Term; i++)
		{
			sum+=(double)1/(double)(a*i);
		}
		System.out.println(sum);
             break;
                 case 4:
                     System.out.println("ENTER FIRST TERM, COMMON DIFFERENCE AND THE NUMBER OF terms TERM ");
            
	      firstTerm = in.nextDouble();
             
              cd=in.nextInt();
               Term = in.nextDouble();
              a = 1/firstTerm;
		 ans = a + (Term-1)*cd;
		double ans1 = (double)1/(double)ans;
		System.out.println(ans1);
             break;
                 case 5:
                      System.out.println("ENTER first TERM, LAST TERM, COMMON DIFFERENCE AND THE NUMBER OF TERMS  ");
             
	      firstTerm = in.nextDouble();
             lastTerm = in.nextDouble();
              cd=in.nextInt();
              int n = in.nextInt();
		 a = 1/firstTerm;
		for(int i=1; i<=n; i++)
		{
			 ans = (double)1/(double)(a*i);
			System.out.print(ans+ "  ");
		}
		System.out.println();
             break;
             default: 
             System.out.println("WRONG INPUT");
             break;
             }
             break;
             case 2:
              int ch2;
             System.out.println("ENTER 1 TO PRINT SEQUENCE");
             System.out.println("ENTER 2 TO FIND required term");
              System.out.println("ENTER 3 TO FIND TO FIND sum of terms");
              System.out.println("ENTER 4 to find arithmetic mean ");
              
              ch2=in.nextInt();
     switch(ch2)
     {
         case 1:
             System.out.println("ENTER FIRST TERM AND COMMON DIFFERENCE  ");
	      double a = in.nextDouble();
             
             int d=in.nextInt();
                   double a2 = a + d;
        double a3 = a2 + d;
        double a4 = a3 + d;
        double a5 = a4 + d;
        String s = "ARITHMETIC SEQUENCE:" + a + "," + a2 + "," + a3 + "," + a4 + "," + a5 + ",...";
        String an = a + " + (n-1)" + d;
        System.out.println(s);
        System.out.println("nth TERM IS GIVEN AS:" + an);
         break;
         case 2:
                     double res;
                     System.out.println("ENTER THE NUMBER OF TERMS");
                     int n=in.nextInt();
                     System.out.println("ENTER FIRST TERM AND COMMON DIFFERENCE");
                     a=in.nextDouble();
                     d=in.nextInt();
        double p = n - 1;
        res = a + p * d;
        System.out.println("REQUIRED TERM:" + res);
        break;
         
         case 3:
             System.out.println("ENTER FIRST TERM , COMMON DIFFERENCE AND  NUMBER OF TERMS");
             a=in.nextFloat();
             d=in.nextInt();
             n=in.nextInt();
                     float sum;
        p = (float)n;
        res = p / 2 * (2 * a + (n - 1) * d);
        System.out.println("ANSWERS:" + res);
        break;
         case 4:
             System.out.println("ENTER THE NUMBER OF TERMS ");
             n=in.nextInt();
             float arr[]=new float[n];
             System.out.println("ENTER THE NUMBEROF THE SEQUENCE");
              for (int i = 0; i < n; i++)
              {
                  arr[i]=in.nextInt();
              }
                      sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + arr[i];
         
         res = sum / n;
        System.out.println("ARITHMETIC MEAN:" + res);
       break;
       default: 
             System.out.println("WRONG  INPUT");
             break;
     }
       break;
         case 3:
                      System.out.println("ENTER THE NUMBEROF TERMS OF FIBONACCI YOU WANT ");
            int n=in.nextInt();
     int f1 = 0, f2 = 1;
        String s = Integer.toString(f1) + " " + Integer.toString(f2);
        while (n != 0) {
            int temp = f2;
            f2 = f2 + f1;
            s = s + " " + Integer.toString(f2);
            f1 = temp;
            n--;
        }
        System.out.println(s);
             break;
         case 4:
             System.out.println("ENTER 1 TO PRINT SEQUENCE");
             System.out.println("ENTER 2 TO FIND Nth TERM");
              System.out.println("ENTER 3 TO FIND SUM OF SERIES");
              System.out.println("ENTER 4 TO FIND GEOMETRIC MEAN");
              
             int ch3=in.nextInt();
     switch(ch3)
     {
         case 1:
             System.out.println("ENTER FIRST TERM, LAST TERM and COMMON RATIO");
             int first=in.nextInt();
              n=in.nextInt();
             float cr=in.nextFloat();
             int curr_term; 
        for (int i = 0; i < n; i++) { 
            curr_term = first * (int)Math.pow(cr, i); 
            System.out.println(curr_term + " ");
           
        }
        
         break;
         case 2:
             System.out.println("ENTER FIRST TERM, NUMBER OF TERMS and COMMON RATIO");
              first=in.nextInt();
              n=in.nextInt();
              cr=in.nextFloat();
              System.out.println(( first * (int)(Math.pow(cr, n - 1))));
              break;
         case 3:
              
              System.out.println("ENTER FIRST TERM, NUMBER OF TERMS and COMMON RATIO");
              float a=in.nextFloat();
              n=in.nextInt();
              cr=in.nextFloat();
              float sum = 0;  
        for (int i = 0; i < n; i++) 
        { 
            sum = sum + a; 
            a = a * cr; 
        } 
        System.out.println(sum);
        break;
         case 4:
             System.out.println("gm");
              
        float product = 1; 
  
        System.out.println("ENTER NUMBER OF TERMS OF GEOMETRIC PROGRESSION");
        n=in.nextInt();
        float arr[]=new float[n];
        System.out.println("ENTER THE NUMBERS");
        for(int i=0;i<n;i++)
        {
            arr[i]=in.nextFloat();
        }
        for (int i = 0; i < n; i++) 
            product = product * arr[i]; 
  
    
        float gm = (float)Math.pow(product, (float)1 / n); 
        System.out.println(gm);
        break;
         default:
             System.out.println("WRONG INPUT");
             break;
             
    }
    
         break;
         default: 
             System.out.println("WRONG INPUT");
             
    }
      
    }
  
   
    }
}

/*
SAMPLE I/O:
A MENU DRIVEN PROGRAM FOR MATHEMATICAL SEQUENCES AND SERIES 
1->HARMONIC  OPERATIONS
2-> ARITHMETIC  OPERATIONS
3->FIBONACCI  GENERATION
4->GEOMETRIC  OPERATION
ENTER YOUR CHOICE
2
ENTER 1 TO PRINT SEQUENCE
ENTER 2 TO FIND required term
ENTER 3 TO FIND TO FIND sum of terms
ENTER 4 to find arithmetic mean 
1
ENTER FIRST TERM AND COMMON DIFFERENCE  
1
2
ARITHMETIC SEQUENCE:1.0,3.0,5.0,7.0,9.0,...
nth TERM IS GIVEN AS:1.0 + (n-1)2
1->HARMONIC  OPERATIONS
2-> ARITHMETIC  OPERATIONS
3->FIBONACCI  GENERATION
4->GEOMETRIC  OPERATION

*/
    
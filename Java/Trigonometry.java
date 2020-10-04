import java.util.Scanner;

public class Trigonometry {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean quit = false;
        double temp=0;
        while (!quit == true) {
            printMenu();
            int option = scanner.nextInt();
            scanner.nextLine();

            switch (option) {
                case 1:
                    temp =enter();
                    System.out.println("***************************");
                    System.out.println("Sine("+temp+") is "+Math.sin(temp));
                    System.out.println("***************************");
                    break;
                case 2:
                    temp =enter();
                    System.out.println("***************************");
                    System.out.println("Cosine("+temp+") is "+Math.cos(temp));
                    System.out.println("***************************");
                    break;
                case 3:
                    temp =enter();
                    System.out.println("***************************");
                    System.out.println("Tangent("+temp+") is "+Math.tan(temp));
                    System.out.println("***************************");
                    break;
                case 4:
                    temp =enter();
                    System.out.println("***************************");
                    System.out.println("Tangent("+temp+") is "+1/Math.tan(temp));
                    System.out.println("***************************");
                    break;
                case 5:
                    temp =enter();
                    System.out.println("***************************");
                    System.out.println("Tangent("+temp+") is "+1/Math.sin(temp));
                    System.out.println("***************************");
                    break;
                case 6:
                    temp =enter();
                    System.out.println("***************************");
                    System.out.println("Tangent("+temp+") is "+1/Math.cos(temp));
                    System.out.println("***************************");
                    break;
                case 7:
                    quit = true;
                    System.out.println("Thankyou  quiting now ");
                    break;
                default:
                    System.out.println("Please enter withing the range");
            }
        }
    }

    /**
     * printing default menu
     */
    public static void printMenu() {
        System.out.println("Enter 1 to find Sine");
        System.out.println("Enter 2 to find Cosine");
        System.out.println("Enter 3 to find Tangent");
        System.out.println("Enter 4 to find Cotangent");
        System.out.println("Enter 5 to find Cosecant");
        System.out.println("Enter 6 to find Secant");
        System.out.println("Enter 7 to quit ");

    }
    public static double enter(){
        System.out.println("Enter the angle in radians");
        double angle=scanner.nextDouble();
        scanner.nextLine();
        return angle;
    }
}
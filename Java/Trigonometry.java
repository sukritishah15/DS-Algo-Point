import java.util.Scanner;

public class Trigonometry {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean quit = false;
        while (!quit == true) {
            printMenu();
            int option = scanner.nextInt();
            scanner.nextLine();

            switch (option) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    quit = true;
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
        System.out.println("Enter 5 to find Secant");
        System.out.println("Enter 6 to find Cosecant");
        System.out.println("Enter 7 to quit");

    }
}
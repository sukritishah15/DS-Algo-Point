public class SwapNumbersWithoutThirdVariable {
    public static void main(String[] args) {
        int x = 9;
        int y = 4;

        x = x + y;
        y = x - y;
        x = x - y;

        System.out.println(x);
        System.out.println(y);
    }
}

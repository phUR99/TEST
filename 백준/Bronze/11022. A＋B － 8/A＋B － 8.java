import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            int num1 = input.nextInt();
            int num2 = input.nextInt();
            System.out.printf("Case #%d: %d + %d = %d\n", i + 1, num1, num2, num1 + num2);
        }
    }

}
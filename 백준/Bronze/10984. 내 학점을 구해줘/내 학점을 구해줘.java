import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {

            int n = input.nextInt();
            double sum = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {

                int num = input.nextInt();
                double grade = input.nextDouble();
                sum += num * grade;
                cnt += num;
            }
            System.out.printf("%d %.1f\n", cnt, sum / cnt);
        }
    }
}

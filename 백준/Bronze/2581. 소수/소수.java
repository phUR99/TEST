import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static boolean isPrime[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
        }
        int value = 10001;
        int sum = 0;
        for (int i = m; i <= n; i++) {
            if (isPrime[i]) {
                sum += i;
                value = Math.min(value, i);
            }
        }
        if (sum == 0) {
            System.out.println(-1);
        } else
            System.out.printf("%d\n%d\n", sum, value);
        br.close();
    }
}
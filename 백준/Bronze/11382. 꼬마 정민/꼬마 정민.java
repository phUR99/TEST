import java.util.Scanner;

class P11382 {
    void solve() {
        Scanner input = new Scanner(System.in);
        long A = input.nextLong();
        long B = input.nextLong();
        long C = input.nextLong();
        System.out.print(A + B + C);
    }
}

public class Main {
    public static void main(String[] args) {
        new P11382().solve();
    }
}

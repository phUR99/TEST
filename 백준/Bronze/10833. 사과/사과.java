import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayList<Integer> schoolList = new ArrayList<>(), appleList = new ArrayList();
        for (int i = 0; i < n; i++) {
            schoolList.add(input.nextInt());
            appleList.add(input.nextInt());
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += appleList.get(i) % schoolList.get(i);
        }
        System.out.print(ret);
    }
}

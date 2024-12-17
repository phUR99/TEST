import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        long num1 = input.nextLong();
        long num2 = input.nextLong();
        System.out.println(Math.abs(num1 - num2));
    }
}
import java.io.BufferedReader;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.*;

public class Main {
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        HashSet<Integer> a = new HashSet<>();
        HashSet<Integer> b = new HashSet<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            b.add(Integer.parseInt(st.nextToken()));
        }
        int ret = 0;
        for (Integer integer : a) {
            if (!b.contains(integer))
                ret++;
        }
        for (Integer integer : b) {
            if (!a.contains(integer))
                ret++;
        }
        System.out.println(ret);
    }
}

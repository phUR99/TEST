import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] arr;
    static int[][] cache;
    static int n, m;

    static int caching(int sum, int turn) {
        if (sum == 0)
            return 0;
        if (cache[sum][turn] != -1)
            return cache[sum][turn];
        int ret = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            if (sum - turn * arr[i] >= 0)
                ret = Math.max(ret, caching(sum - turn * arr[i], turn + 1) + arr[i]);
        }
        cache[sum][turn] = ret;
        return ret;
    }

    static void solve(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        cache = new int[n + 5][105];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(cache[i], -1);
        }
        int ret = caching(n, 1);
        if (ret < 0) {
            ret = -1;
        }
        System.out.println(ret);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve(br);
        }
    }
}

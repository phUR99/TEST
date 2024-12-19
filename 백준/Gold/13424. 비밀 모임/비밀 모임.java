import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int dist[][];
    static boolean checked[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve(br);
        }
    }

    public static void solve(BufferedReader br) throws IOException {
        String str = br.readLine();
        StringTokenizer s = new StringTokenizer(str);
        int n = Integer.parseInt(s.nextToken());
        int m = Integer.parseInt(s.nextToken());
        dist = new int[n + 1][n + 1];
        checked = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = 987654321;
            }
            dist[i][i] = 0;
            checked[i] = false;
        }
        for (int i = 0; i < m; i++) {
            str = br.readLine();
            s = new StringTokenizer(str);
            int a = Integer.parseInt(s.nextToken());
            int b = Integer.parseInt(s.nextToken());
            int c = Integer.parseInt(s.nextToken());
            dist[a][b] = Math.min(dist[a][b], c);
            dist[b][a] = Math.min(dist[b][a], c);
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        str = br.readLine();
        int k = Integer.parseInt(str);
        str = br.readLine();
        s = new StringTokenizer(str);
        for (int i = 0; i < k; i++) {
            int num = Integer.parseInt(s.nextToken());
            checked[num] = true;
        }
        int sum = 987654321;
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 1; j <= n; j++) {
                if (checked[j]) {
                    tmp += dist[j][i];
                }

            }
            if (tmp < sum) {
                sum = tmp;
                idx = i;
            }
        }
        System.out.println(idx);
    }
}
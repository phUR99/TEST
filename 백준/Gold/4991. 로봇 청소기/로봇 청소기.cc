#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int w, h;
char board[25][25];
int dist[25][25][(1 << 10) - 1];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    fastio;
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        memset(dist, -1, sizeof(dist));
        int cnt = 0;
        pair<int, int> st;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '*')
                    board[i][j] = cnt++ + '0';
                if (board[i][j] == 'o')
                    st = {i, j};
            }
        }
        int full_bit = (1 << cnt) - 1;
        queue<vector<int>> q;
        q.push({st.first, st.second, 0});
        dist[st.first][st.second][0] = 0;
        int answer = 987654321;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur[0];
            int y = cur[1];
            int b = cur[2];
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (board[nx][ny] == 'x')
                    continue;
                int nxtBit = b;
                if (isdigit(board[nx][ny]))
                {
                    nxtBit = (1 << (board[nx][ny] - '0'));
                    // || 논리연산자  vs | 비트연산자
                    nxtBit = nxtBit | b;
                }
                if (dist[nx][ny][nxtBit] != -1)
                    continue;
                dist[nx][ny][nxtBit] = dist[x][y][b] + 1;
                q.push({nx, ny, nxtBit});
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (dist[i][j][full_bit] == -1)
                    continue;
                answer = min(answer, dist[i][j][full_bit]);
            }
        }
        if (answer == 987654321)
            answer = -1;
        cout << answer << '\n';
    }

    return 0;
}
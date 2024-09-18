#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<vector<int>> arr;
int n;
int board[500][500];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool oob(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}
float dust[5][5] =
    {

        {
            0,
            0,
            0.02,
            0,
            0,
        },
        {0, 0.1, 0.07, 0.01, 0},
        {0.05, -1, 0, 0, 0},
        {0, 0.1, 0.07, 0.01, 0},
        {
            0,
            0,
            0.02,
            0,
            0,
        }

};
vector<vector<float>> copyBoard(int cnt)
{
    vector<vector<float>> ret, tmp;
    tmp.resize(5);
    ret.resize(5);
    for (int i = 0; i < 5; i++)
    {
        ret[i].resize(5, 0);
        tmp[i].resize(5, 0);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[i][j] = dust[i][j];
            ret[i][j] = dust[i][j];
        }
    }
    for (int k = 0; k < cnt; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                ret[4 - j][i] = tmp[i][j];
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                tmp[i][j] = ret[i][j];
            }
        }
    }
    return ret;
}
int solve(int x, int y, int dir)
{
    int ret = 0;
    vector<vector<float>> table = copyBoard(dir);
    int now = board[x][y];
    int nx = -1;
    int ny = -1;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int cx = x - 2 + i;
            int cy = y - 2 + j;
            int cur = (float)now * table[i][j];
            if (table[i][j] == -1)
            {
                nx = cx;
                ny = cy;
                continue;
            }
            if (oob(cx, cy))
            {
                ret += cur;
                continue;
            }
            board[cx][cy] += cur;
            sum += cur;
        }
    }

    int nxt = now - sum - ret;
    if (oob(nx, ny))
    {
        ret += nxt;
    }
    else
    {
        board[nx][ny] += nxt;
    }
    board[x][y] = 0;
    return ret;
}

void makeShape()
{
    int cnt = 0;
    int x = n / 2;
    int y = n / 2;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            cnt %= 4;
            for (int j = 1; j <= k; j++)
            {

                x = x + dx[cnt];
                y = y + dy[cnt];
                if (oob(x, y))
                    return;
                arr.push_back({cnt, x, y});
            }
            cnt++;
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    makeShape();
    int answer = 0;
    for (auto e : arr)
    {
        int x = e[1];
        int y = e[2];
        int dir = e[0];
        answer += solve(x, y, dir);
        // print();
    }
    cout << answer;
    return 0;
}
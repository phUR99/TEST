#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
// →, ←, ↑, ↓
#define LEFT 2
#define RIGHT 1
#define UP 3
#define DOWN 4
using namespace std;
vector<vector<vector<int>>> board;
int boardColor[15][15];
int nowDir[15];
int n, k;

void findPos(int &x, int &y, int cur)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j].empty())
                continue;
            if (board[i][j][0] == cur)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}
void nextPos(int &x, int &y, int dir)
{
    if (dir == UP)
    {
        x -= 1;
    }
    else if (dir == DOWN)
    {
        x += 1;
    }
    else if (dir == LEFT)
    {
        y -= 1;
    }
    else
    {
        y += 1;
    }
}
int changeDir(int dir)
{
    if (dir == UP)
        return DOWN;
    else if (dir == DOWN)
        return UP;
    else if (dir == LEFT)
        return RIGHT;
    else
        return LEFT;
}
int solve()
{
    int cnt = 1;
    while (cnt <= 1000)
    {
        for (int cur = 1; cur <= k; cur++)
        {
            int x = -1, y = -1;
            findPos(x, y, cur);
            if (x == -1)
                continue;
            int &dir = nowDir[cur];
            int nx = x;
            int ny = y;
            nextPos(nx, ny, dir);
            bool already = false;
            if (nx < 1 || nx > n || ny < 1 || ny > n)
            {
                dir = changeDir(dir);
                nx = x;
                ny = y;
                nextPos(nx, ny, dir);
                already = true;
            }
            if (boardColor[nx][ny] == 2)
            {
                dir = changeDir(dir);
                if (already)
                    continue;
                nx = x;
                ny = y;
                nextPos(nx, ny, dir);
                if (nx < 1 || nx > n || ny < 1 || ny > n)
                {
                    dir = changeDir(dir);
                    continue;
                }

                if (boardColor[nx][ny] == 2)
                {
                    dir = changeDir(dir);
                    continue;
                }
            }
            vector<int> &nowBoard = board[x][y];
            vector<int> &nxtBoard = board[nx][ny];
            if (boardColor[nx][ny] == 0)
            {
                for (auto e : nowBoard)
                {
                    nxtBoard.push_back(e);
                }
                nowBoard.clear();
            }
            else if (boardColor[nx][ny] == 1)
            {
                reverse(nowBoard.begin(), nowBoard.end());
                for (auto e : nowBoard)
                {
                    nxtBoard.push_back(e);
                }
                nowBoard.clear();
            }
            if (nxtBoard.size() >= 4)
                return cnt;
        }
        cnt++;
    }
    return -1;
}

int main()
{
    fastio;
    cin >> n >> k;
    board.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        board[i].resize(n + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> boardColor[i][j];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        int x, y, dir;
        cin >> x >> y >> dir;
        board[x][y].push_back(i);
        nowDir[i] = dir;
    }
    int answer = solve();
    cout << answer;

    return 0;
}
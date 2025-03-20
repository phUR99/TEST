#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int r, c;
char board[105][105], tmp_board[105][105];
void copy()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            board[i][j] = tmp_board[i][j];
            if (board[i][j] == 'D')
                board[i][j] = '.';
            tmp_board[i][j] = '.';
        }
    }
}
void findI(int &x, int &y)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'I')
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}
bool move(char d)
{
    int dd = d - '0';
    dd--;
    int x, y;
    findI(x, y);
    x += dx[dd];
    y += dy[dd];
    if (board[x][y] == 'R')
        return false;
    tmp_board[x][y] = 'I';
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] != 'R')
                continue;
            int dist = 987654321;
            int idx = -1;
            for (int dir = 0; dir < 9; dir++)
            {
                int nx = dx[dir] + i;
                int ny = dy[dir] + j;
                if (dist > abs(x - nx) + abs(y - ny))
                {
                    // cout << dist << '\n';
                    dist = abs(x - nx) + abs(y - ny);
                    idx = dir;
                }
            }
            assert(idx >= 0);
            int nx = dx[idx] + i;
            int ny = dy[idx] + j;
            if (nx == x && ny == y)
                return false;
            if (tmp_board[nx][ny] == 'R')
                tmp_board[nx][ny] = 'D';
            if (tmp_board[nx][ny] == 'D')
                continue;
            tmp_board[nx][ny] = 'R';
        }
    }
    return true;
}

string directions;
int main()
{
    fastio;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            tmp_board[i][j] = '.';
        }
    }
    cin >> directions;
    for (int i = 0; i < directions.size(); i++)
    {
        if (move(directions[i]))
        {
            copy();
        }
        else
        {
            cout << "kraj " << i + 1;
            return 0;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
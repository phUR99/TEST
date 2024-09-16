#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define EMPTY 0
using namespace std;

int board[10][10];
int n;
int answer = 0;
vector<pair<int, int>> returnShape(int type)
{
    vector<pair<int, int>> ret;
    ret.push_back({0, 0});
    if (type == 2)
    {
        ret.push_back({0, 1});
    }
    else if (type == 3)
    {
        ret.push_back({1, 0});
    }
    return ret;
}
int moveRow(int x, int y, vector<pair<int, int>> &cur)
{
    int ret = 9999;
    for (auto e : cur)
    {
        int xx = e.first;
        int yy = e.second + y;
        int i;
        for (i = 1; i < 10; i++)
        {
            if (board[i][yy] != EMPTY)
                break;
        }
        ret = min(ret, i - xx - 1);
    }
    return ret;
}
int moveCol(int x, int y, vector<pair<int, int>> &cur)
{
    int ret = 9999;
    for (auto e : cur)
    {
        int xx = e.first + x;
        int yy = e.second;
        int i;
        for (i = 1; i < 10; i++)
        {
            if (board[xx][i] != EMPTY)
                break;
        }
        ret = min(ret, i - yy - 1);
    }
    return ret;
}
void checkRow()
{
    int cnt = 0;
    for (int i = 6; i < 10; i++)
    {
        bool isClear = true;
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == EMPTY)
                isClear = false;
        }
        if (isClear)
        {
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = 0;
                for (int r = i; r > 0; r--)
                {
                    swap(board[r][j], board[r - 1][j]);
                }
            }
            answer++;
        }
    }
}
void checkCol()
{
    for (int i = 6; i < 10; i++)
    {
        bool isClear = true;
        for (int j = 0; j < 4; j++)
        {
            if (board[j][i] == EMPTY)
                isClear = false;
        }
        if (isClear)
        {
            for (int j = 0; j < 4; j++)
            {
                board[j][i] = 0;
                for (int c = i; c > 0; c--)
                {
                    swap(board[j][c], board[j][c - 1]);
                }
            }
            answer++;
        }
    }
}
void deleteRow()
{
    int cnt = 0;
    for (int i = 4; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != EMPTY)
            {
                cnt++;
                break;
            }
        }
    }
    for (int i = 9; i > 9 - cnt; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = EMPTY;
        }
    }
    int tmpBoard[15][15];
    memset(tmpBoard, 0, sizeof(tmpBoard));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tmpBoard[j + cnt][i] = board[j][i];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[j][i] = tmpBoard[j][i];
        }
    }
}
void deleteCol()
{
    int cnt = 0;
    for (int i = 4; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[j][i] != EMPTY)
            {
                cnt++;
                break;
            }
        }
    }
    for (int i = 9; i > 9 - cnt; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            board[j][i] = EMPTY;
        }
    }
    int tmpBoard[15][15];
    memset(tmpBoard, 0, sizeof(tmpBoard));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tmpBoard[i][j + cnt] = board[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = tmpBoard[i][j];
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        auto curBlock = returnShape(type);
        int rowDepth = moveRow(x, y, curBlock);
        int colDepth = moveCol(x, y, curBlock);
        for (auto cur : curBlock)
        {
            int xx = cur.first;
            int yy = cur.second;
            board[rowDepth + xx][y + yy] = i;
            board[x + xx][colDepth + yy] = i;
        }
        checkRow();
        checkCol();
        deleteRow();
        deleteCol();
    }
    cout << answer << '\n';
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] != EMPTY)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
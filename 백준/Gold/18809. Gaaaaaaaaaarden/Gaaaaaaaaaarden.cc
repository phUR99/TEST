#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m, g, r;
int board[55][55];
vector<int> arr;
vector<pair<int, int>> coord;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solve()
{
    queue<pair<int, int>> redQ, greenQ, redBufferQ, greenBufferQ;
    bool isFlower[55][55];
    int visitedRed[55][55], visitedGreen[55][55];
    memset(isFlower, 0, sizeof(isFlower));
    memset(visitedRed, -1, sizeof(visitedRed));
    memset(visitedGreen, -1, sizeof(visitedGreen));
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            redQ.push(coord[i]);
            int x = coord[i].first;
            int y = coord[i].second;
            visitedRed[x][y] = 0;
        }
        else if (arr[i] == 0)
        {
            greenQ.push(coord[i]);
            int x = coord[i].first;
            int y = coord[i].second;
            visitedGreen[x][y] = 0;
        }
    }

    do
    {
        while (!redBufferQ.empty())
        {
            redQ.push(redBufferQ.front());
            redBufferQ.pop();
        }
        while (!greenBufferQ.empty())
        {
            greenQ.push(greenBufferQ.front());
            greenBufferQ.pop();
        }
        while (!redQ.empty())
        {
            auto cur = redQ.front();
            redQ.pop();
            int x = cur.first;
            int y = cur.second;
            if (isFlower[x][y])
                continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (visitedRed[nx][ny] != -1 || isFlower[nx][ny] || board[nx][ny] == 0)
                    continue;
                visitedRed[nx][ny] = visitedRed[x][y] + 1;
                redBufferQ.push({nx, ny});
            }
        }
        while (!greenQ.empty())
        {
            auto cur = greenQ.front();
            greenQ.pop();
            int x = cur.first;
            int y = cur.second;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (visitedGreen[nx][ny] != -1 || isFlower[nx][ny] || board[nx][ny] == 0)
                    continue;
                if (visitedRed[nx][ny] != -1 && visitedRed[nx][ny] == visitedGreen[x][y] + 1)
                {
                    isFlower[nx][ny] = true;
                    continue;
                }
                visitedGreen[nx][ny] = visitedGreen[x][y] + 1;
                greenBufferQ.push({nx, ny});
            }
        }
    } while (!redBufferQ.empty() || !greenBufferQ.empty());
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret += isFlower[i][j];
        }
    }

    return ret;
}

int main()
{
    fastio;

    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                coord.push_back({i, j});
                arr.push_back(2);
            }
        }
    }
    for (int i = 0; i < g; i++)
    {
        arr[i] = 0;
    }
    for (int i = g; i < g + r; i++)
    {
        arr[i] = 1;
    }
    int answer = 0;
    do
    {
        answer = max(answer, solve());

    } while (next_permutation(arr.begin(), arr.end()));
    cout << answer;
    return 0;
}
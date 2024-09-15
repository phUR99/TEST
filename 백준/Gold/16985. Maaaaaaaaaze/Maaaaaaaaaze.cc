#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int shape[5][5][5];
int board[5][5][5];
int dist[5][5][5];
void copy(vector<int> &a)
{
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board[i][j][k] = shape[i][j][a[k]];
            }
        }
    }
}
vector<vector<int>> rot;
int rotArr[5];

void makeRot(int cnt)
{
    if (cnt == 5)
    {
        vector<int> tmp;
        for (int i = 0; i < 5; i++)
        {
            tmp.push_back(rotArr[i]);
        }
        rot.push_back(tmp);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        rotArr[cnt] = i;
        makeRot(cnt + 1);
    }
}

void rotate(int cur)
{
    int tmpBoard[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmpBoard[j][4 - i] = board[i][j][cur];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j][cur] = tmpBoard[i][j];
        }
    }
}
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int answer = 987654321;
int bfs()
{
    queue<vector<int>> q;
    if (board[0][0][0] == 0 || board[4][4][4] == 0)
        return 987654321;
    dist[0][0][0] = 0;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int z = cur[2];
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5)
                continue;
            if (dist[nx][ny][nz] != -1 || board[nx][ny][nz] == 0)
                continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            if (nx == 4 && ny == 4 && nz == 4)
                return dist[nx][ny][nz];
            q.push({nx, ny, nz});
        }
    }
    return 987654321;
}

int main()
{
    fastio;
    vector<int> arr = {0, 1, 2, 3, 4};
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> shape[i][j][k];
            }
        }
    }
    makeRot(0);

    do
    {

        for (vector<int> vec : rot)
        {
            copy(arr);
            memset(dist, -1, sizeof(dist));
            for (int i = 0; i < 5; i++)
            {
                for (int k = 0; k < vec[i]; k++)
                {
                    rotate(i);
                }
            }
            answer = min(bfs(), answer);
            if (answer == 12)
                break;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    if (answer == 987654321)
        answer = -1;

    cout << answer;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, K;
/*
회전의 규칙을 파악하자
(1, 1) -> (2, 1) -> (2, 2) -> (3 ,2) -> (3, 3)...
*/
vector<vector<int>> board;

bool if_end()
{
    int max_fishes = *max_element(board[0].begin(), board[0].end());
    int min_fishes = *min_element(board[0].begin(), board[0].end());
    return ((max_fishes - min_fishes) <= K);
}

void move_fishes()
{
    vector<vector<int>> new_board = board;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (board[y][x] == -1)
                continue;
            for (int d = 0; d < 4; ++d)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == -1)
                    continue;
                // 새로운 값을 new_board 에 기록했으므로 중복 없이 모든 칸에 발생한 상황 반영
                new_board[y][x] += (int)(board[ny][nx] - board[y][x]) / 5;
            }
        }
    }

    vector<int> flat_bowl;
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < N; ++y)
        {
            if (new_board[y][x] == -1)
                continue;
            else
                flat_bowl.push_back(new_board[y][x]);
        }
    }

    // board를 초기화 한 후 board[0]를 flat_bowl로 교체
    board = vector<vector<int>>(N, vector<int>(N, -1));
    board[0] = flat_bowl;
}

void move()
{
    int ly = 1, lx = 1; // length y, length x
    int sx = 0;         // start x
    // 1. 물고기 추가
    int min_fishes = *min_element(board[0].begin(), board[0].end());
    for (int i = 0; i < N; ++i)
    {
        if (board[0][i] == min_fishes)
            board[0][i]++;
    }
    // 2. 어항을 말며 이동
    while (sx + ly + lx <= N)
    {
        for (int y = 0; y < ly; ++y)
        {
            for (int x = 0; x < lx; ++x)
            {
                int ny = lx - x;
                int nx = sx + lx + y;
                board[ny][nx] = board[y][x + sx];
                board[y][x + sx] = -1;
            }
        }
        sx += lx;
        if (ly == lx)
            ly++;
        else
            lx++;
    }

    // 3. 물고기 이동
    move_fishes();

    // 4. 중심을 기준으로 어항 2번 이동
    sx = 0;
    ly = 1;
    lx = N / 2;

    for (int i = 0; i < 2; ++i)
    {
        for (int y = 0; y < ly; ++y)
        {
            for (int x = 0; x < lx; ++x)
            {
                int ny = 2 * ly - y - 1;
                int nx = 2 * lx + sx - x - 1;
                board[ny][nx] = board[y][x + sx];
                board[y][x + sx] = -1;
            }
        }

        sx += lx;
        lx /= 2;
        ly *= 2;
    }

    // 5. 물고기 이동
    move_fishes();
}

int solve()
{
    int count = 0;
    while (!if_end())
    {
        count++;
        move();
    }

    return count;
}

int main()
{
    cin >> N >> K;
    board = vector<vector<int>>(N, vector<int>(N, -1));
    for (int i = 0; i < N; ++i)
    {
        cin >> board[0][i];
    }
    cout << solve();
    return 0;
}
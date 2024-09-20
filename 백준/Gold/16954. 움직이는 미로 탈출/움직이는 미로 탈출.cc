
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

string a[8];
const int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
const int dx[9] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
bool check[9][8][8];

int main()
{
    for (int i = 0; i < 8; ++i)
        cin >> a[i];

    queue<tuple<int, int, int>> q;
    q.push({0, 7, 0});
    check[0][7][0] = true;

    int ans = 0;
    while (!q.empty())
    {
        int t, y, x;
        tie(t, y, x) = q.front();
        q.pop();

        if (y == 0 && x == 7)
            ans = 1;

        for (int i = 0; i < 9; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nt = min(t + 1, 8);

            if (!(0 <= ny && ny < 8 && 0 <= nx && nx < 8))
                continue;
            if (ny - t >= 0 && a[ny - t][nx] == '#')
                continue;
            if (ny - t - 1 >= 0 && a[ny - t - 1][nx] == '#')
                continue;

            if (!check[nt][ny][nx])
            {
                check[nt][ny][nx] = true;
                q.push({
                    nt,
                    ny,
                    nx,
                });
            }
        }
    }
    if (ans)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int status[11][11];
bool visited[11];

int solve(int idx)
{
    if (idx == 11)
        return 0;
    int ret = -987654321;
    for (int i = 0; i < 11; i++)
    {
        if (status[idx][i] == 0 || visited[i])
            continue;
        visited[i] = 1;
        ret = max(ret, status[idx][i] + solve(idx + 1));
        visited[i] = 0;
    }
    return ret;
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                cin >> status[i][j];
            }
        }
        int ret = solve(0);

        cout << ret << '\n';
    }

    return 0;
}
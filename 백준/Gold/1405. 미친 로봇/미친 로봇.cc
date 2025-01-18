#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool visited[30][30];
int n;
double prob[4];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
double solve(int x, int y, int cnt)
{
    if (visited[x][y])
        return 0;
    if (cnt == n)
        return 1;
    double ret = 0;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret += solve(nx, ny, cnt + 1) * prob[i];
    }
    visited[x][y] = false;
    return ret;
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        double a;
        cin >> a;
        prob[i] = a / 100;
    }
    double ret = solve(n, n, 0);
    cout.precision(9);
    cout << fixed << ret;
    return 0;
}
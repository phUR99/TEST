#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int cache[61 * 61 * 61];
const int MX = 987654321;
int dx[][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}};

int solve(int state)
{
    if (state <= 0)
        return 0;
    int &ret = cache[state];
    if (ret != -1)
        return ret;
    ret = MX;
    vector<int> tmp;
    tmp.push_back(state % 61);
    tmp.push_back(state % (61 * 61) / 61);
    tmp.push_back(state / (61 * 61));
    for (int dir = 0; dir < 6; dir++)
    {
        int nxtA = max(tmp[0] - dx[dir][0], 0);
        int nxtB = max(tmp[1] - dx[dir][1], 0);
        int nxtC = max(tmp[2] - dx[dir][2], 0);
        ret = min(ret, 1 + solve(nxtA + nxtB * 61 + nxtC * 61 * 61));
    }
    return ret;
}

vector<int> arr;
int n;

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    arr.resize(3, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int state = arr[0] + arr[1] * 61 + arr[2] * 61 * 61;
    int ret = solve(state);
    cout << ret << '\n';
    return 0;
}
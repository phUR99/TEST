#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int arr[5005];
bool solve(int x)
{
    int cnt = 0;
    int MX = -1;
    int MN = 987654321;
    for (int i = 0; i < n; i++)
    {
        if (max(MX, arr[i]) - min(MN, arr[i]) > x)
        {
            cnt++;
            MX = -1;
            MN = 987654321;
        }
        MX = max(MX, arr[i]);
        MN = min(MN, arr[i]);
    }
    return cnt < m;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = 10000 * 5000;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (solve(m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int n;
int arr[55];
int cache[55][55];
const int MN = -987654321;

int minimax(int left, int right)
{
    if (left > right)
        return 0;
    int &ret = cache[left][right];
    if (ret != MN)
        return ret;
    if (right - left >= 1)
    {
        ret = -min(minimax(left + 2, right), minimax(left, right - 2));
    }
    return ret = max({ret, arr[left] - minimax(left + 1, right), arr[right] - minimax(left, right - 1)});
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cache[i][j] = MN;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = minimax(0, n - 1);
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
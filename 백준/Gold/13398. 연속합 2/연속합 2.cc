#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int arr[100005];
int n;
int cache[100005][2];
const int MN = -1987654321;

int main()
{
    fastio;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << arr[0] << '\n';
        return 0;
    }
    cache[0][0] = arr[0];
    int ret = MN;
    for (int i = 1; i < n; i++)
    {
        cache[i][0] = max(arr[i], cache[i - 1][0] + arr[i]);
        cache[i][1] = max(cache[i - 1][0], cache[i - 1][1] + arr[i]);
        ret = max({cache[i][0], cache[i][1], ret});
    }
    cout << ret << '\n';
    return 0;
}
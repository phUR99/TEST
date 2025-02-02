#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[4][1005];
void solve()
{
    int v, n;
    cin >> v >> n;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> sum1, sum2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1.push_back(arr[0][i] + arr[1][j]);
            sum2.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    sum1.erase(unique(sum1.begin(), sum1.end()), sum1.end());
    sum2.erase(unique(sum2.begin(), sum2.end()), sum2.end());
    int diff = 987654321;
    int ret = -1;
    for (auto &i : sum1)
    {
        int j = lower_bound(sum2.begin(), sum2.end(), v - i) - sum2.begin();
        if (j != sum2.size() && diff > abs(v - sum2[j] - i))
        {
            diff = abs(v - sum2[j] - i);
            ret = sum2[j] + i;
        }
        if (j == 0)
            continue;
        if (diff > abs(v - sum2[j - 1] - i))
        {
            diff = abs(v - sum2[j - 1] - i);
            ret = sum2[j - 1] + i;
        }
        else if (diff == abs(v - sum2[j - 1] - i))
        {
            ret = min(ret, sum2[j - 1] + i);
        }
    }
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
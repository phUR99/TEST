#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dist[105][105];

void solve()
{
    memset(dist, 0x3f, sizeof(dist));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int k;
    cin >> k;
    vector<int> people(k);
    for (auto &i : people)
    {
        cin >> i;
    }
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (auto &person : people)
        {
            sum += dist[person][i];
        }
        arr.push_back(sum);
    }
    int idx = min_element(arr.begin(), arr.end()) - arr.begin() + 1;
    cout << idx << '\n';
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
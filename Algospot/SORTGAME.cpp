#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<vector<int>, int> dist;
void pre_calculation(int n)
{
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i);
    }
    dist[arr] = 0;
    queue<vector<int>> q;
    q.push(arr);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int cost = dist[cur];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2; j <= n; j++)
            {
                reverse(cur.begin() + i, cur.begin() + j);
                if (dist.count(cur) == 0)
                {
                    dist[cur] = cost + 1;
                    q.push(cur);
                }
                reverse(cur.begin() + i, cur.begin() + j);
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    vector<int> fixed(n);
    for (int i = 0; i < n; i++)
    {
        int order = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
                order++;
        }
        fixed[i] = order;
    }
    cout << dist[fixed] << '\n';
}

int main()
{

    for (int i = 1; i <= 8; i++)
    {
        pre_calculation(i);
    }

    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
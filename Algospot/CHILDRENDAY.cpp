#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int append(int here, int edge, int mod)
{
    int there = here * 10 + edge;
    if (there >= mod)
        return mod + there % mod;
    return there % mod;
}

void solve()
{
    string d;
    int n, m;
    cin >> d >> n >> m;
    sort(d.begin(), d.end());
    vector<int> visited(2 * n, -1), parent(2 * n, -1);
    parent[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (auto i : d)
        {
            int there = append(here, i - '0', n);
            if (parent[there] == -1)
            {
                parent[there] = here;
                visited[there] = i - '0';
                q.push(there);
            }
        }
    }
    if (parent[n + m] == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        string ret;
        for (int here = n + m; here != parent[here]; here = parent[here])
        {
            ret += char('0' + visited[here]);
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }
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
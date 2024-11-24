#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
dist[i][j] + edge[i][j]가 갱신되지 않더라도 dist[i][j] 자체는 갱신될 수 있다는 사실을 파악못함

*/
int dist[505][505];
int edge[505][505];
int n, m;
vector<int> crackdown;
vector<int> order;

bool cmp(const int &a, const int &b)
{
    return crackdown[a] < crackdown[b];
}

int main()
{
    fastio;
    cin >> n >> m;
    crackdown.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> crackdown[i];
        order.push_back(i);
    }
    sort(order.begin(), order.end(), cmp);
    memset(dist, 0x3f, sizeof(dist));
    memset(edge, 0x3f, sizeof(edge));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
        edge[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = dist[a][b] = c;
        edge[b][a] = dist[b][a] = c;
    }

    for (int iter = 0; iter < n; iter++)
    {
        int k = order[iter];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                edge[i][j] = min(dist[i][k] + dist[k][j] + crackdown[k], edge[i][j]);
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << edge[a][b] << '\n';
    }

    return 0;
}
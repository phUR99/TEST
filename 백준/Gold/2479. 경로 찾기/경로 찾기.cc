#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
vector<int> arr;
vector<int> bfs(int s, int e)
{
    queue<int> q;
    q.push(s);
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    dist[s] = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there = 0; there < arr.size(); there++)
        {
            if (__builtin_popcount(arr[here] ^ arr[there]) != 1)
                continue;
            if (dist[there] != -1)
                continue;
            dist[there] = dist[here] + 1;
            q.push(there);
            parent[there] = here;
        }
    }
    if (dist[e] == -1)
        return vector<int>();
    vector<int> ret;
    for (int here = e; here != -1; here = parent[here])
    {
        ret.push_back(here);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        bitset<30> b;
        cin >> b;
        arr.push_back((int)b.to_ulong());
    }
    int s, e;
    cin >> s >> e;
    s--, e--;
    vector<int> ret = bfs(s, e);
    if (ret.empty())
        cout << -1;
    else
    {
        for (int e : ret)
        {
            cout << e + 1 << ' ';
        }
    }

    return 0;
}
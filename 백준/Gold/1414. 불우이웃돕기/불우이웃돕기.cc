#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int N;
int parent[55];
int trans(char c)
{
    if (c < 'a')
        return c - 'A' + 27;
    else
        return c - 'a' + 1;
}
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u] = v;
}

int main()
{
    fastio;
    cin >> N;
    vector<vector<int>> arr;
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char dist;
            cin >> dist;
            if (dist == '0')
                continue;
            arr.push_back({trans(dist), i, j});
            answer += trans(dist);
        }
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int d = arr[i][0];
        int u = arr[i][1];
        int v = arr[i][2];
        if (find(u) == find(v))
            continue;
        cnt++;
        merge(u, v);
        answer -= d;
    }
    if (cnt == N - 1)
        cout << answer;
    else
        cout << -1;

    return 0;
}
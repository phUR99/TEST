#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int parent[1005];
/*
파란 간선의 개수를 최소로 사용해서 얻을 수 있는 스패닝 트리 t1
파란 간선의 개수를 최대로 사용해서 얻을 수 있는 스패닝 트리 t2
1. t1에서 파란 간선을 하나 추가한다 -> 사이클이 생긴다
2. 사이클에서 빨간 간선을 하나 제거한다.
3. 이 과정을 t2가 될때까지 반드시 계속할 수 있다.
따라서 t1과 t2 과정 사이에 tk가 있다면 반드시 만들수 있다.
*/
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
vector<vector<int>> arr;
int search(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int ret = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int c = arr[i][0];
        int u = arr[i][1];
        int v = arr[i][2];
        if (find(u) == find(v))
            continue;
        merge(u, v);
        ret += c;
    }
    return ret;
}

int main()
{
    fastio;
    while (true)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0)
            break;
        arr.clear();
        for (int i = 0; i < m; i++)
        {
            char c;
            int u, v;
            cin >> c >> u >> v;
            if (c == 'B')
                arr.push_back({1, u, v});
            else
                arr.push_back({0, u, v});
        }
        sort(arr.begin(), arr.end(), greater<>());
        int M = search(n);
        reverse(arr.begin(), arr.end());
        int mm = search(n);
        if (mm <= k && k <= M)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}
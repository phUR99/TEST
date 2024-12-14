#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int main()
{
    fastio;
    cin >> n >> m;
    priority_queue<int> pq;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    vector<int> children(m);
    for (auto &i : children)
    {
        cin >> i;
    }
    for (int i = 0; i < m; i++)
    {
        int child = children[i];
        if (child > pq.top())
        {
            cout << 0;
            return 0;
        }
        pq.push(pq.top() - child);
        pq.pop();
    }

    cout << 1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const int MX = 1e6;
int pos[MX + 5];
int n;
int main()
{
    fastio;
    memset(pos, -1, sizeof(pos));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pos[x] = y;
    }
    pos[MX + 1] = 0;
    stack<int> s;
    s.push(0);
    int cnt = 0;
    for (int i = 1; i <= MX + 1; i++)
    {
        if (pos[i] == -1)
            continue;
        while (!s.empty() && s.top() > pos[i])
        {
            s.pop();
            cnt++;
        }
        if (s.top() != pos[i])
            s.push(pos[i]);
    }
    cout << cnt;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool visited[1505][1505];

int main()
{
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({min({a, b, c}), max({a, b, c})});
    visited[q.front().first][q.front().second] = true;
    
    while (!q.empty())
    {
        auto here = q.front();
        q.pop();
        int l = here.first;
        int r = here.second;
        int m = sum - l - r;
        pair<int, int> c1 = {min({l + l, r - l, m}),
                             max({l + l, r - l, m})};
        if (!visited[c1.first][c1.second])
        {
            visited[c1.first][c1.second] = true;
            q.push(c1);
        }
        c1 = {min({l + l, r, m - l}),
              max({l + l, r, m - l})};
        if (!visited[c1.first][c1.second])
        {
            visited[c1.first][c1.second] = true;
            q.push(c1);
        }
        c1 = {min({l, r - m, m + m}),
              max({l, r - m, m + m})};
        if (!visited[c1.first][c1.second])
        {
            visited[c1.first][c1.second] = true;
            q.push(c1);
        }
    }
    cout << visited[sum / 3][sum / 3];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int parent[20005];
int choice[20005];
string digits = "01";
void solve()
{
    memset(parent, -1, sizeof(parent));
    memset(choice, -1, sizeof(choice));
    int n;
    cin >> n;
    queue<int> q;
    q.push(1);
    parent[1] = -2;
    choice[1] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (auto i : digits)
        {
            int there = (here * 10 + (i - '0')) % (n);
            if (parent[there] == -1)
            {
                parent[there] = here;
                choice[there] = i - '0';
                q.push(there);
            }
        }
    }
    if (parent[0] == -1)
    {
        cout << "BRAK\n";
    }
    else
    {
        string ret;
        int i;
        for (i = 0; i != -2; i = parent[i])
        {
            ret += char('0' + choice[i]);
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
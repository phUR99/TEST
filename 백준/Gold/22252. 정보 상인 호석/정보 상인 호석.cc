#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<string, priority_queue<int>> info;
int n;

int main()
{
    fastio;
    cin >> n;
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        int cmd;
        string str;
        cin >> cmd >> str;
        if (cmd == 1)
        {
            int t;
            cin >> t;
            while (t--)
            {
                int m;
                cin >> m;
                info[str].push(m);
            }
        }
        else
        {
            int num;
            cin >> num;
            while (!info[str].empty() && num--)
            {
                ret += info[str].top();
                info[str].pop();
            }
        }
    }
    cout << ret;
    return 0;
}
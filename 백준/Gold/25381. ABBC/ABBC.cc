#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string str;
int main()
{
    fastio;
    cin >> str;
    int n = str.size();
    queue<int> q;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'B')
            q.push(i);
        if (str[i] == 'C' && !q.empty())
        {
            int x = q.front();
            q.pop();
            str[x] = 'C';
            ret++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A')
            cnt++;
        if (str[i] == 'B' && cnt)
        {
            cnt--;
            ret++;
        }
    }
    cout << ret;

    return 0;
}
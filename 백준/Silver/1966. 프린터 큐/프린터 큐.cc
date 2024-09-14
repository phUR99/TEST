#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int T, N, O;
int prior[15];
bool isAblePop(pair<int, int> cur)
{
    for (int i = cur.second + 1; i < 10; i++)
    {
        if (prior[i])
            return false;
    }
    return true;
}
int main()
{
    fastio;
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> O;
        queue<pair<int, int>> q;
        memset(prior, 0, sizeof(prior));
        for (int i = 0; i < N; i++)
        {
            int c;
            cin >> c;
            q.push({i, c});
            prior[c]++;
        }
        int cnt = 0;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if (!isAblePop(cur))
            {
                q.push(cur);
            }
            else
            {
                prior[cur.second]--;
                cnt++;
                if (cur.first == O)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
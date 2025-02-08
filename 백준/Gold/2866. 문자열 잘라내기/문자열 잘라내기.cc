#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string board[1005];

int main()
{
    fastio;
    unordered_set<string> dict;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            board[j] += c;
        }
    }
    for (int i = 0; i < m; i++)
    {
        reverse(board[i].begin(), board[i].end());
        board[i].pop_back();
    }
    int ret = 0;
    for (int i = 0; i < n - 1; i++)
    {
        dict.clear();
        for (int j = 0; j < m; j++)
        {
            if (dict.count(board[j]))
            {
                cout << ret;
                return 0;
            }
            dict.insert(board[j]);
            board[j].pop_back();
        }
        ret++;
    }
    cout << ret;
    return 0;
}
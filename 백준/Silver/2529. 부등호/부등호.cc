#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
char board[11];
bool visited[11];
int n;
vector<string> answer;
void solve(int idx, string &str)
{
    if (idx == n + 1)
    {
        answer.push_back(str);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (visited[i])
            continue;
        if (idx == 0 || (board[idx] == '<' && str.back() < i + '0') || (board[idx] == '>' && str.back() > i + '0'))
        {
            str.push_back(i + '0');
            visited[i] = true;
            solve(idx + 1, str);
            visited[i] = false;
            str.pop_back();
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> board[i];
    }
    string str;
    solve(0, str);
    sort(answer.begin(), answer.end());
    cout << answer.back() << '\n'
         << answer.front() << '\n';
    return 0;
}
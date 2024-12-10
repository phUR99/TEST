#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
string str;
int answer = INT_MIN;
int cal(int a, int b, char oper)
{
    int result = a;
    switch (oper)
    {
    case '+':
        result += b;
        break;
    case '*':
        result *= b;
        break;
    case '-':
        result -= b;
        break;
    }
    return result;
}
void solve(int idx, int cur)
{
    if (idx >= n)
    {
        answer = max(answer, cur);
        return;
    }
    char op = (idx == 0) ? '+' : str[idx - 1];
    if (idx + 2 < n)
    {
        int val = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        solve(idx + 4, cal(cur, val, op));
    }
    solve(idx + 2, cal(cur, str[idx] - '0', op));
}
int main()
{
    fastio;

    cin >> n;
    cin >> str;
    solve(0, 0);
    cout << answer;

    return 0;
}
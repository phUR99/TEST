#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int num;
int n;
bool error[10];
const int MX = 987654321;
int ret;
int s;

void solve(int idx, int val)
{
    if (idx == s + 1)
        return;
    for (int i = 0; i < 10; i++)
    {
        if (error[i])
            continue;
        int nxtVal = val * 10 + i;
        ret = min(ret, abs(nxtVal - num) + idx + 1);
        solve(idx + 1, nxtVal);
    }
}

int main()
{
    fastio;
    cin >> num;
    s = to_string(num).size();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        error[idx] = true;
    }
    ret = abs(num - 100);
    solve(0, 0);
    cout << ret << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void dfs(int num, int from, int by, int to)
{
    if (num == 0)
        return;
    dfs(num - 1, from, to, by);
    cout << from << ' ' << to << '\n';
    dfs(num - 1, by, from, to);
}

int main()
{
    fastio;
    int n;
    cin >> n;
    string a = to_string(pow(2, n));
    a = a.substr(0, a.find('.'));
    a[a.length() - 1] -= 1;
    cout << a << '\n';
    if (n <= 20)
        dfs(n, 1, 2, 3);
    return 0;
}
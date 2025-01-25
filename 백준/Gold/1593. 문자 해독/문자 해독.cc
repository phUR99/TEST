#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string w, g;
int dict[60];
int temp[60];
bool matching()
{
    for (int i = 0; i < 60; i++)
    {
        if (dict[i] != temp[i])
            return false;
    }
    return true;
}
int main()
{
    fastio;
    auto transform = [](char c)
    { if (isupper(c)) return c - 'A' + 26; else return c - 'a'; };
    int n, m;
    cin >> n >> m;
    cin >> w >> g;
    for (int i = 0; i < n; i++)
    {
        dict[transform(w[i])]++;
        temp[transform(g[i])]++;
    }
    int cnt = matching();
    for (int i = n; i < m; i++)
    {
        temp[transform(g[i - n])]--;
        temp[transform(g[i])]++;
        cnt += matching();
    }
    cout << cnt;
    return 0;
}
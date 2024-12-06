#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string arr[15];
ll cache[100][1 << 15];
ll table[15][100];
int n, k;

void preProcessing()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int remain = j;
            for (auto &c : arr[i])
            {
                remain = (remain * 10 + (c - '0')) % k;
            }
            table[i][j] = remain;
        }
    }
}
ll solve(int residue, int state)
{
    if (state == (1 << n) - 1)
        return residue == 0;
    ll &ret = cache[residue][state];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
            continue;
        int nxtState = state | (1 << i);
        int newResidue = table[i][residue];
        ret += solve(newResidue, nxtState);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    ll mother = 1;
    for (int i = 1; i <= n; i++)
    {
        mother *= i;
    }
    ll ret = 0;
    preProcessing();
    for (int i = 0; i < n; i++)
    {
        ret += solve(table[i][0], (1 << i));
    }
    if (ret == 0)
        cout << "0/1";
    else
    {
        ll gcd = __gcd(mother, ret);
        cout << ret / gcd << "/" << mother / gcd;
    }

    return 0;
}
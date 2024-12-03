#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<int> arr;
int n;
int cache[5][5][100050];
int power(int now, int nxt)
{

    if (now == 0)
        return 2;
    if (now == nxt)
        return 1;
    if (abs(now - nxt) == 2)
        return 4;
    return 3;
}

int solve(int l, int r, int idx)
{
    if (idx == n)
        return 0;
    int &ret = cache[l][r][idx];
    if (ret != -1)
        return ret;
    ret = 987654321;
    if (arr[idx] != r)
        ret = min(ret, power(l, arr[idx]) + solve(arr[idx], r, idx + 1));
    if (arr[idx] != l)
        ret = min(ret, power(r, arr[idx]) + solve(l, arr[idx], idx + 1));
    return ret;
}

int main()
{
    fastio;

    while (1)
    {
        int e;
        cin >> e;
        if (e == 0)
            break;
        arr.push_back(e);
    }
    memset(cache, -1, sizeof(cache));
    n = arr.size();
    int ret = solve(0, 0, 0);
    cout << ret;
    return 0;
}
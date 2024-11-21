#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
1. 완전탐색 : 가능한 숫자를 전부 나열한 뒤에 m으로 나눠지는 지를 확인
-> 동일한 수의 중복 문제가 있으나, 정렬한 뒤에 비트마스킹을 활용하는 방식으로 중복 해결
2. 메모이제이션에서의 문제
    1. 다 만든 가격이 m의 배수인 지를 확인하는 부분 -> m으로 나눈 나머지를 넘겨줘서 확인
    2. 다 만든 가격이 n보다 작은지를 확인하는 부분  -> 정보로 less를 추가해서 확인
*/
int cache[(1 << 14)][20][2];
string e, digits;
int m, n;
int d = 1e9 + 7;
int price(int idx, int state, int mod, int less)
{

    if (idx == n)
        return (less && mod == 0);
    int &ret = cache[state][mod][less];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int nxt = 0; nxt < n; nxt++)
    {
        if (state & (1 << nxt))
            continue;
        if (!less && e[idx] < digits[nxt])
            continue;
        if (nxt > 0 && digits[nxt - 1] == digits[nxt] && (state & (1 << (nxt - 1))) == 0)
            continue;
        int nxtState = state | (1 << nxt);
        int nxtMod = (mod * 10 + digits[nxt] - '0') % m;
        int nxtLess = less || (e[idx] > digits[nxt]);
        ret += price(idx + 1, nxtState, nxtMod, nxtLess);
        ret %= d;
    }
    return ret;
}

void solve()
{
    memset(cache, -1, sizeof(cache));
    cin >> e >> m;
    n = e.size();
    digits = e;
    sort(digits.begin(), digits.end());
    int ret = price(0, 0, 0, 0);
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
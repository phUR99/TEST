#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
더 간단하게 모델링
1. p ~ p+l번째를 구하는게 아니라 p번째를 구하는 알고리즘 짜기
2. 디버깅 시 assert 구문 사용 가능
*/
const int MX = 1e9 + 1231;
int cache[51];
void preCalc()
{
    cache[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        cache[i] = min(MX, cache[i - 1] * 2 + 2);
    }
}
const string X = "X+YF";
const string Y = "FX-Y";

char func(const string &curve, int gen, int skip)
{
    if (gen == 0)
    {
        // assert(skip < curve.size());
        return curve[skip];
    }
    for (int i = 0; i < curve.size(); i++)
    {
        if (curve[i] == 'X' || curve[i] == 'Y')
        {
            if (skip >= cache[gen])
            {
                skip -= cache[gen];
            }
            else if (curve[i] == 'X')
                return func(X, gen - 1, skip);
            else
                return func(Y, gen - 1, skip);
        }
        else if (skip > 0)
            --skip;
        else
            return curve[i];
    }
}

void solve()
{

    int n, p, l;
    cin >> n >> p >> l;
    string ans;
    for (int i = p - 1; i < p + l - 1; i++)
    {
        ans += func("FX", n, i);
    }
    cout << ans;
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    preCalc();
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
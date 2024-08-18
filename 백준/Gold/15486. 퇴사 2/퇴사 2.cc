#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int cost[1500005];
int score[1500005];
int N;
int cache[1500005]; // i번째부터 시작했을 때 얻을 수 있는 최대의 값

int solve(int cur)
{
    if (cur > N + 1)
        return -987654321;
    if (cur == N + 1)
        return 0;

    int &ret = cache[cur];
    if (ret != -1)
        return ret;

    ret = max(solve(cur + cost[cur]) + score[cur], solve(cur + 1));
    return ret;
}

int main()
{
    fastio;
    cin >> N;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i] >> score[i];
    }
    int answer = solve(1);
    cout << answer;

    return 0;
}
#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int cache[10005][10];
int now[10005], goal[10005];
int n;
// 현재 인덱스, 왼쪽으로 돌아간 정도
int solve(int cur, int left)
{
    if (cur == n)
        return 0;
    int &ret = cache[cur][left];
    if (ret != -1)
        return ret;
    ret = 0;
    // 현재값 0 기준으로 오른쪽으로 몇칸 떨어저있는지
    int state = (goal[cur] + left) % 10;

    ret = min(solve(cur + 1, (left - state + 10) % 10) + state, solve(cur + 1, left) + 10 - state);
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        now[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        goal[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        goal[i] -= now[i];
        goal[i] = (goal[i] + 10) % 10;
    }

    int answer = solve(0, 0);
    cout << answer;
    return 0;
}
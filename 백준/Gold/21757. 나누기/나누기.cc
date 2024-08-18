#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int arr[100005];
int N;
int sum = 0;
long long cache[100005][5];

long long solve(int cur, int cnt)
{
    if (cnt == 0)
    {
        if (cur != 0)
            return 0;
        else
            return 1;
    }
    if (cur == 0)
        return 0;
    long long &ret = cache[cur][cnt];
    if (ret != -1)
        return ret;
    ret = 0;
    int s = 0;
    for (int i = cur; i > 0; i--)
    {
        s += arr[i];
        if (s == sum)
            ret += solve(i - 1, cnt - 1);
    }

    return ret;
}

int main()
{
    fastio;
    cin >> N;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sum /= 4;
    long long answer = solve(N, 4);
    cout << answer;
    return 0;
}
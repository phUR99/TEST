#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define val first
#define num second
int T, N;
int sum;
vector<pair<int, int>> arr;
int cache[105][100005];

int solve(int cur, int money)
{
    if (money == 0)
        return 1;
    if (cur == -1 || money < 0)
        return 0;
    int &ret = cache[cur][money];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i <= arr[cur].num; i++)
    {
        ret |= solve(cur - 1, money - i * arr[cur].val);
    }
    return ret;
}
int main()
{
    fastio;
    for (int t = 0; t < 3; t++)
    {
        sum = 0;
        cin >> N;
        arr.clear();
        arr.resize(N);
        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i].val >> arr[i].num;
            sum += arr[i].val * arr[i].num;
        }
        if (sum % 2 == 1)
        {
            cout << "0\n";
            continue;
        }
        bool answer = solve(N - 1, sum / 2);
        cout << answer << '\n';
    }

    return 0;
}
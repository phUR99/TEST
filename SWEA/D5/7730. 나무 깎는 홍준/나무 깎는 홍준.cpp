#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int T;
int N;
int arr[1'000'005];
long long H;
bool solve(long long x)
{
    long long now = 0;
    for (int i = 0; i < N; i++)
    {
        now += max(0LL, arr[i] - x);
    }
    return now >= H;
}
int main()
{
    fastio;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> N >> H;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        long long left, right;
        left = 0;
        right = 2'000'000'000;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if (solve(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << "#" << test_case << ' ';
        cout << right << '\n';
    }

    return 0;
}
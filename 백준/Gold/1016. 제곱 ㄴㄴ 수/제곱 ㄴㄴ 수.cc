#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

long long number[1000005];

int main()
{
    fastio;
    long long l, r;
    cin >> l >> r;
    int answer = 0;
    for (long long i = 2; i * i <= r; i++)
    {
        long long cur = l / (i * i);
        if (l % (i * i))
            cur++;
        while (cur * (i * i) <= r)
        {
            number[cur * i * i - l] = 1;
            cur++;
        }
    }
    for (int i = 0; i <= r - l; i++)
    {
        answer += !number[i];
    }
    cout << answer;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
ll k;

void Hanoi(int n, long long mid, int from, int to, int by)
{
    if (n == 1)
    {
        cout << from << " " << to;
        return;
    }
    else if (k < mid)
    {
        Hanoi(n - 1, (long long)(pow(2, n - 1)) / 2, from, by, to);
    }
    else if (k > mid)
    {
        k -= mid; // 1번,2번 수행 횟수를 k에서 빼줌
        Hanoi(n - 1, (long long)(pow(2, n - 1)) / 2, by, to, from);
    }
    else if (k == mid)
    {
        cout << from << " " << to;
        return;
    }
}
int main()
{
    fastio;
    cin >> n >> k;
    long long total = (long long)(pow(2, n));

    Hanoi(n, total / 2, 1, 3, 2);

    return 0;
}
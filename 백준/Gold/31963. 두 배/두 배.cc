#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll arr[255555];
int cache[250005];
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cache[i] = cache[i - 1];

        if (arr[i - 1] >= arr[i])
        {
            ll now = arr[i];
            while (now < arr[i - 1])
            {
                now *= 2;
                cache[i]++;
            }
        }
        else
        {
            ll now = arr[i - 1];
            while (now * 2 <= arr[i])
            {
                now *= 2;
                cache[i]--;
            }
            cache[i] = max(0, cache[i]);
        }
        cnt += cache[i];
    }
    cout << cnt;

    return 0;
}
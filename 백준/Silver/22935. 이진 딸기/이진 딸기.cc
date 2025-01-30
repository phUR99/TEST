#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    ll T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        N--;
        N %= 28;
        N++;
        if (16 <= N)
            N = 30 - N;

        for (ll i = 8; i >= 1; i /= 2)
        {
            if (N >= i)
            {
                cout << "딸기";
                N -= i;
            }
            else
                cout << "V";
        }
        cout << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<int, ll> towns;

int main()
{
    fastio;
    int n;
    cin >> n;
    ll totalPeople = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        towns[a] = b;
        totalPeople += b;
    }
    ll people = 0;
    for (auto iter : towns)
    {
        people += iter.second;
        if (people * 2 >= totalPeople)
        {
            cout << iter.first;
            return 0;
        }
    }

    return 0;
}
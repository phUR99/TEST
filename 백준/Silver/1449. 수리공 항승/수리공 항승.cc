#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int main()
{
    fastio;

    int n, l;
    cin >> n >> l;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < v.size();)
    {
        count++;
        int tape = v[i] + l - 1;
        while (i < v.size() && v[i] <= tape)
        {
            i++;
        }
    }
    cout << count << endl;
}
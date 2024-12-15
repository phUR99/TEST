#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
set<int> plug;
int n, k;
vector<int> arr;
int ret = 0;

void erase(int begin)
{

    priority_queue<pair<int, int>> pq;
    for (auto iter : plug)
    {
        int order = 987654321;
        for (int i = begin + 1; i < arr.size(); i++)
        {
            if (arr[i] == iter)
            {
                order = i;
                break;
            }
        }
        pq.push({order, iter});
    }

    int del = pq.top().second;
    // cout << del << ' ';
    plug.erase(del);
    ret++;
    assert(begin < k);
    plug.insert(arr[begin]);
}
int main()
{
    fastio;
    cin >> n >> k;
    arr.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        if (plug.size() < n || plug.count(arr[i]))
            plug.insert(arr[i]);
        else
            erase(i);
    }
    cout << ret;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache_increase[2005];
int cache_decrease[2005];
int n;
int arr[2005];

int solve1(int idx){

    int &ret= cache_increase[idx];
    if(ret != -1) return ret;
    ret = 1;
    for (int i = idx + 1; i < n; i++)
    {
        if(arr[i] > arr[idx])
            ret = max(ret, solve1(i) + 1);
    }
    return ret;
}
int solve2(int idx){

    int &ret= cache_decrease[idx];
    if(ret != -1) return ret;
    ret = 1;
    for (int i = idx + 1; i < n; i++)
    {
        if(arr[i] < arr[idx])
            ret = max(ret, solve2(i) + 1);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(cache_decrease, -1, sizeof(cache_decrease));
    memset(cache_increase, -1, sizeof(cache_increase));
    solve1(0);
    solve2(0);
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret = max(solve1(i) + solve2(i) -1, ret);
    }
    cout << ret;
    return 0;
}
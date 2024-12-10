#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
하한선의 설정 이유 파악하기
1. 하한선이 최대 원소값 이하일 경우 조건에 문제가 생긴다.(1번 조건에 강제적으로 갈 수 있음)
*/
int n, m;
int arr[100005];

bool solve(int x)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < arr[i])
            return false;
        if (sum + arr[i] > x)
        {
            sum = arr[i];
            cnt++;
        }
        else
            sum += arr[i];
    }
    return cnt < m;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = 1e9 + 10;
    while (l <= r)
    {
        int x = (l + r) / 2;
        if (solve(x))
            r = x - 1;
        else
            l = x + 1;
    }
    cout << l;
    return 0;
}
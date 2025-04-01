#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int a, b, d, n;
queue<ll> life, dead, mature;
deque<ll> dq;
int main()
{
    fastio;
    cin >> a >> b >> d >> n;
    
    for (int i = 0; i < d-1; i++)
    {
        dq.push_front(0);
    }
    dq.push_front(1);
    int sum = 0;
    for (int i = 0; i <n; i++)
    {
        ll adult = dq[a-1];
        sum += dq[a-1];
        ll old = dq[b-1];
        sum -= dq[b-1];
        sum = (sum+1000)%1000;
        dq.push_front(sum);
        dq.pop_back();    
    }
    int ret =0;
    while (!dq.empty())
    {
        ret += dq.front(); dq.pop_front();
        ret %= 1000;
    }
    
    
    
    cout << ret;
    
    

    return 0;
}